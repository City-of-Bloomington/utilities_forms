<?php
require_once '../configuration.inc';

//CHECK CAPTCHA FIRST THING AND EXIT IF NOT VALID
if(!isset($_POST['g-recaptcha-response']) || checkCaptcha($_POST) === false) {
	exit;
}

function checkCaptcha($vals) {
	$options = array(
		CURLOPT_POST			=> true,
		CURLOPT_HEADER			=> true,
		CURLOPT_RETURNTRANSFER	=> true,
		CURLOPT_SSL_VERIFYPEER	=> false,
		CURLOPT_POSTFIELDS		=> 
			array(
				'secret' 		=> "[secret-key-goes-here]",
				'response'		=> $vals['g-recaptcha-response'],
				'remoteip'		=> $_SERVER['REMOTE_ADDR']
			)
	);
	$verifierURL = "https://www.google.com/recaptcha/api/siteverify";
	$verifier = curl_init($verifierURL);
	curl_setopt_array($verifier, $options);
	$response = curl_exec($verifier);
	$header_size = curl_getinfo($verifier, CURLINFO_HEADER_SIZE);
	$header = substr($response, 0, $header_size);
	$body = substr($response, $header_size);
	$json = json_decode($body,true);
	$result = $json['success'];
	if($result == true) {
		return true;
	}
	else {
		return false;
	}
}


//ENSURE THE CORRECT DATA IS PRESENT, MAKE UPPERCASE, AND REMOVE ANY TAGS IN THE POSTED DATA BEFORE CREATING THE FORM OBJECT
if (isset($_POST)) {
	if (count($_POST) > 1 && isset($_POST['DocumentType'])) {
		$_POST['dateTimeStamp'] = date("Y-m-d H:i:s",time());

		foreach ($_POST as $key => $post) {
			$_POST[$key] = strtoupper(strip_tags($post));
		}
		
		if(isset($_POST['g-recaptcha-response'])) {
			unset($_POST['g-recaptcha-response']);
		}

		$addressFields = [
            'OBKey__225_1' => 'OBKey__226_1',
            'OBKey__225_2' => 'OBKey__226_2',
            'OBKey__225_3' => 'OBKey__226_3',
            'OBKey__225_4' => 'OBKey__226_4',
            'OBKey__225_5' => 'OBKey__226_5'
		];
		foreach ($addressFields as $streetNumber=>$streetDirection) {
            if (empty($_POST[$streetNumber]) && isset($_POST[$streetDirection])) {
                $_POST[$streetDirection] = '';
            }
		}

		$Forms = new Forms($_POST);
	}
}


class Forms {
    private $vals = [];
    private $Valid_Counter = 0;
    private $Docs = 0;
    private $Files;

    private $Conf_Number;
    private $supp_dip_path;
    private $supp_image_file_name;
    private $supp_image_temp_path;
    private $form_dip_path;
    private $form_html_filename;
    private $form_html_path;
    private $form_pdf_filename;
    private $form_pdf_path;

    public static $validExtensions = ['jpg', 'png', 'gif', 'tiff', 'pdf'];


	//SETUP VARIABLES AND PATHS AND CALL FUNCTIONS DEPENDING ON THE REQUEST
	public function __construct($vals = false)
	{
		$this->vals = $vals;
		$this->Valid_Counter = 0;
		$this->Files = [];

		//SPECIAL FIELDS
		if ($this->vals['DocumentType'] === "SPECIALREADAGREEMENTCANCELLATION") {
			$this->vals['OBKey__188_1'] = date("m/d/Y",time());
		}
		if ($this->vals['DocumentType'] === "SPECIALREADAGREEMENT") {
			$this->vals['OBKey__209_1'] = date("m/d/Y",time());
		}

		//IF THE REQUEST IS A NORMAL FORM SUBMISSION
		if (   $this->vals['DocumentType'] !== "SUPPLEMENTARYDOCUMENT"
            && $this->vals['DocumentType'] !== "") {

			$this->Get_Next_Conf_Number();
			$this->vals['Conf_Number'] = $this->Conf_Number;
			$this->Setup_Paths();
			if (isset($_FILES['Sup_File_1']['name']) && $_FILES['Sup_File_1']['name'] != "") {
				$this->Create_Supp_DIP($this->Validate_File_Uploads($_FILES));
			}

			//REMOVED SPECIAL READ AGREEMENT HTML CREATION PER JOSH ON 2016-02-15
			if ($_POST['DocumentType'] !== "SPECIALREADAGREEMENT") {
				$this->Create_Form_HTML();
			}
			$this->Create_Form_DIP();
		}
		//IF THE REQUEST IS A SUPPLEMENTAL DOCUMENT SUBMISSION
		elseif ($this->vals['DocumentType'] === "SUPPLEMENTARYDOCUMENT"
                && isset($_FILES) && isset($this->vals['Conf_Number'])) {
			$this->Setup_Paths();
			$this->Create_Supp_DIP($this->Validate_File_Uploads($_FILES));
		}
		//IF THE REQUEST IS NEITHER A SUPPLEMENTAL DOCUMENT OR A NORMAL FORM SUBMISSION RETURN ERROR
		elseif ($this->vals['DocumentType'] !== "") {
			exit("error");
		}
	}

	private function Setup_Paths()
	{
        $date = date('YmdHis');

		//CHANGE DEFAULT PATHS AND FILENAMES BELOW
		if (isset($this->vals['Conf_Number'])) {
			//SUPPLEMENTARY IMAGE FILES AND DIP FILES
			//supp DIP file name example: 20151204122913-000608-0382-supp.txt
			$this->supp_dip_path = TEMP_PATH . "/$date-{$this->vals['Conf_Number']}-supp.txt";

			//supp file name example: 20151204122913-000608-0382-img3.jpg
			$this->supp_image_file_name = "$date-{$this->vals['Conf_Number']}-img";
			$this->supp_image_temp_path = TEMP_PATH;
		}

		//FORM DIP FILES
		//form DIP file example:20151204122846-000608-0382-form.txt
		$this->form_dip_path = TEMP_PATH . "/$date-{$this->Conf_Number}-form.txt";

		//FORM HTML FILES
		//form HTML file example:20151204122846-000608-0382-html.html
		$this->form_html_filename = "$date-{$this->Conf_Number}-html.html";
		$this->form_html_path = TEMP_PATH . "/{$this->form_html_filename}";

		//FORM PDF FILES
		//form PDF file example:20151204122846-000608-0382-form.pdf
		$this->form_pdf_filename = "$date-{$this->Conf_Number}-form.pdf";
		$this->form_pdf_path = TEMP_PATH . "/{$this->form_pdf_filename}";
	}

	//VALIDATE FILE UPLOADS
	private function Validate_File_Uploads($Files)
	{
		$counter = 0;
		foreach ($Files as $File) {		
			if(isset($File['size']) && !empty($File) && $File['size'] > 0 && $File['name'] != "") {
				$counter++;
				//CHECK IF FILESIZES ARE TOO BIG
				if ($File['size'] > 6291456) {
					$this->Files[$counter]['Response'] = "Error: Size";
				}
				//CHECK IF THE FILES ARE NOT THE CORRECT TYPE
				//REMOVED WORD DOCUMENTS PER JOSH REQUEST ON 2015-12-11
				// && substr($File['name'],strpos($File['name'],".")+1,3) != "doc"
				else if (explode("/",$File['type'])[0] !== "image" && $File['type'] !== "application/pdf") {
					$this->Files[$counter]['Response'] = "Error: Invalid";
				}

				try { $extension = self::getExtension($File['name']); }
				catch (\Exception $e) {
					$this->Files[$counter]['Response'] = "Error: {$e->getMessage()}";
				}

				if (empty($this->Files[$counter]['Response'])) {
					$imageFile = "{$this->supp_image_temp_path}/{$this->supp_image_file_name}$counter.$extension";
					if (move_uploaded_file($File["tmp_name"], $imageFile)) {
						self::transferFileToOnBase($imageFile);
						unlink($imageFile);

						$this->Files[$counter]['Response'] = "Success";
						$this->Files[$counter]['Filename'] = basename($imageFile);
						$this->Valid_Counter++;
					}
				}

				$this->Files[$counter]['Old_Filename'] = $File['name'];
				//REMOVE UPLOADED FILE FROM THE SERVER AND UNSET VARIABLE
				if (file_exists($File['tmp_name'])) {
					unlink($File['tmp_name']);
				}
				unset($File);
			}
		}
	}

	//WRITE THE SUPPLEMENTARY DIP FILE
	private function Create_Supp_DIP()
	{
		$data    = "";
		$message = "";
		foreach ($this->Files as $counter => $val) {
			if ($val['Filename'] !== "") {
				$data .= str_pad("DocumentTypeNum:",  30," ",STR_PAD_RIGHT) . "340\r\n";
				$data .= str_pad("Conf_Number:",      30," ",STR_PAD_RIGHT) . $this->vals['Conf_Number'] . "\r\n";
				$data .= str_pad("SupplementaryType:",30," ",STR_PAD_RIGHT) . $this->vals['Sup_Type_'.$counter] . "\r\n";
				$data .= str_pad("Filename:",         30," ",STR_PAD_RIGHT) . $val['Filename'] . "\r\n";
			}
			$message .= "Message[" . $val['Old_Filename']. "]=" . $val['Response'] . "&";
		}

		self::saveToOnBase($this->supp_dip_path, $data);

        if ($this->vals['DocumentType'] === "SUPPLEMENTARYDOCUMENT") {
            $url = BASE_URL."/index.php?form=SuppConfirmation&Confirmation_Number={$this->vals['Conf_Number']}&$message";
            header("Location: $url");
            exit();
        }
	}

	//GET NEXT CONFIRMATION NUMBER AND WRITE NEW CONFIRMATION NUMBER FOR NEXT REQUEST
	private function Get_Next_Conf_Number()
	{
		$file = APPLICATION_HOME.'/data/nextConfirmationNumber';
		$counter = trim(file_get_contents($file));
		if ($counter !== "") {
			$counter = (int)$counter;

			$this->Conf_Number = $counter . "-" . str_pad(rand(0, 9999), 4, "0", STR_PAD_LEFT);

			$counter++;
			if (false === file_put_contents($file, $counter)) {
                throw new \Exception('unable to save conf number');
			}
		}
		else {
			//WRITE CONFIRMATION BACK TO FILE
			//$start = 2000;
			exit("We're sorry, the request could not be completed. Please contact someone at the City of Bloomington Utilities at (812) 349-3930.<br /> <b>Error: </b>Could not get next confirmation number");
		}
	}

	/**
	 * @param array $params ['DocumentType'=>'', 'ob'=>'']
	 * @return array ['docs'=> '', 'dip'=> '']
	 */
	public static function Get_Mapped_Name(array $params)
	{
		static $xml;
		if (!$xml) {
            $xml = simplexml_load_file(APPLICATION_HOME.'/forms.xml') or die("Error: Cannot create object");
        }

		foreach ($xml->form as $form) {
			if (strtoupper($form->file->__toString()) === $params['DocumentType']) {
				#$this->Docs = $form->docs;

				foreach ($form->fields as $val) {
					foreach ($val as $field) {
						if ($field->ob->__toString() === $params['ob']) {
                            return [
                                'docs' => $form->docs->__toString(),
                                'dip'  => $field->dip->__toString()
                            ];
						}
					}
				}
				break(1);
			}
		}
	}

	private function Create_Form_HTML()
	{
		//GET THE FORM HTML AS THE CUSTOMER SEES IT (INCLUDING CSS AND JAVASCRIPT FILES)
		$url = BASE_URL.'/index.php?form=' . strtolower($_POST['DocumentType']) . '&html=true';
		$html = '';
		$lines = file($url);
		foreach ($lines as $line_num => $line) {
			if (strpos($line,"global.js")) {
				$line = str_replace("global.js","onbase.js",$line);
			}
			if (strpos($line,"Global = new Global;")) {
				$line = str_replace("Global = new Global;","",$line);
			}
			if (strpos($line,"Global.init();")) {
				$line = str_replace("Global.init();","init();",$line);
			}
			if (strpos($line,"dateTimeStamp") !== false) {
				$line = str_replace("name=\"dateTimeStamp\"","name=\"dateTimeStamp\" class=\"dateTimeStamp\" ",$line);
			}
			if (strpos($line,"service_row_hidden") !== false) {
				$line = str_replace("service_row_hidden","",$line);
			}
			if (strpos($line,"Add_More_Addresses") !== false) {
				$line = str_replace("Add_More_Addresses","Add_More_Addresses_hide",$line);
			}
			if (strpos($line,"global.css") !== false) {
				$line = str_replace("global.css","onbase.css",$line);
			}
			if (strpos($line,"enctype=\"multipart/form-data\"") !== false) {
				$line = str_replace("enctype=\"multipart/form-data\"","",$line);
			}
			if (strpos($line,"g-recaptcha") !== false) {
				$line = "";
			}


			$m = false;
			foreach ($_POST as $name => $value) {
				//DETECT IF THE LINE INCLUDES THE FIELD ELEMENT ASSOCIATED WITH THE POSTED DATA, ADD THE VALUE TO THE FIELD, AND APPEND THE LINE
				if (strpos($line,"name=\"" . $name . "\"") !== false) {
					$attr = "";
					if (substr($name,0,5) !== "OBKey") {
						$attr = "disabled";
					}
					if (strpos($line,"select") !== false) {
						$html .= substr_replace($line," " . $attr . " ", strpos($line,">"), 0);
						//$html .= $line;
						$html .= "<option selected value=\"" . $value . "\">" . $value . "</option>";
					}
					else if (strpos($line,"type=\"checkbox\"") !== false) {
						$html .= substr_replace($line, " " . $attr . " checked ", strpos($line,">"), 0);
					}
					else {
						$html .= substr_replace($line, " " . $attr . " value=\"" . $value . "\" ", strpos($line,">"), 0);
					}
					//SET MATCHED AS TRUE
					$m = true;
				}
			}
			if ($m == false) {
				//APPEND THE LINE IF IT DOES NOT INCLUDE A FIELD ELEMENT
				if (strpos($line,"name=\"Agree\"") === false && strpos($line,"form-agree choose") === false) {
					$html .= $line;
				}
			}
		}

		self::saveToOnBase($this->form_html_path, $html);
	}

	//WRITE THE FORM DIP FILE
	private function Create_Form_DIP()
	{
		$this->vals['Conf_Number'] = $this->Conf_Number;
		//ADD PER JOSH REQUEST ON 2016-02-17
		if ($_POST['DocumentType'] !== "SPECIALREADAGREEMENT") {
			$this->vals['Filename'] = $this->form_html_filename;
		}
		$data = "";
		foreach ($this->vals as $key => $val) {
            $map = self::Get_Mapped_Name(['DocumentType'=>$this->vals['DocumentType'], 'ob'=>$key]);
            $this->Docs = $map['docs'];
			$data .= str_pad($map['dip'].":",30," ",STR_PAD_RIGHT) . $val . "\r\n";
		}

		self::saveToOnBase($this->form_dip_path, $data);

        $this->Docs = $this->Docs - $this->Valid_Counter;
        $url = BASE_URL."/index.php?form=Confirmation&Confirmation_Number={$this->Conf_Number}&docs={$this->Docs}";
        header("Location: $url");
        exit();
	}

	/**
	 * @param string $filename
	 * @return string
	 */
	public static function getExtension($filename)
	{
		if (preg_match("/[^.]+$/", $filename, $matches)) {
			$extension  = strtolower($matches[0]);
			if (in_array($extension, self::$validExtensions)) {
                return $extension;
			}
			else {
                throw new \Exception('Invalid Extension');
			}
		}
		else {
			throw new \Exception('Missing Extension');
		}
	}

	/**
	 * Writes data to a file on OnBase
	 *
	 * This function uses a temp file on the web server.
	 * The temp file and the file on OnBase will have the same filename
	 *
	 * @param string $file Full path to temp file
	 * @param string $data Data to write to file
	 * @throws \Exception
	 */
	private static function saveToOnBase($file, $data)
	{
        file_put_contents($file, $data);
        if (file_exists($file)) {
            self::transferFileToOnBase($file);
            unlink($file);
        }
        else {
            throw new \Exception('error saving file');
        }
	}

	/**
	 * Takes care of sending a file to OnBase.
	 *
	 * Throws an exception if there's an error.
	 * You must provide the full path to the file on the web server's hard drive
	 *
	 * @param string $file The full path to the file
	 * @throws \Exception
	 */
	private static function transferFileToOnBase($file)
	{
        if (is_file($file)) {
            $filename = basename($file);
            $stream   = fopen($file, 'r');
            $url      = sprintf('ftp://%s/%s', ONBASE_HOST, ONBASE_PATH);
            $options = [
                CURLOPT_UPLOAD     => true,
                CURLOPT_FTP_SSL    => CURLFTPSSL_ALL,
                CURLOPT_FTPSSLAUTH => CURLFTPAUTH_TLS,
                CURLOPT_CONNECTTIMEOUT => 10,
                CURLOPT_TIMEOUT        => 10,
                CURLOPT_INFILESIZE => filesize($file),
                CURLOPT_URL        => "$url/$filename",
                CURLOPT_INFILE     => $stream,
                CURLOPT_CAINFO     => ONBASE_CERT,
                CURLOPT_USERPWD    => ONBASE_USER.':'.ONBASE_PASS
            ];

            $curl = curl_init($url);
            foreach ($options as $key=>$value) {
                if (!curl_setopt($curl, $key, $value)) { throw new \Exception(curl_error($curl)); }
            }

            if (!curl_exec($curl)) { throw new \Exception(curl_error($curl)); }
            fclose($stream);
        }
        else {
            throw new \Exception('unknownFile');
        }
	}
}
