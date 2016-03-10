<?php
include '../configuration.inc';

error_reporting(E_ALL);
ini_set("display_errors", "0");
//ENSURE THE CORRECT DATA IS PRESENT, MAKE UPPERCASE, AND REMOVE ANY TAGS IN THE POSTED DATA BEFORE CREATING THE FORM OBJECT
if(isset($_POST)) {
	if(count($_POST) > 1 && isset($_POST['DocumentType'])) {
		$_POST['dateTimeStamp'] = date("Y-m-d H:i:s",time());
		foreach($_POST as $key => $post) {
			//REMOVED PER REQUEST FROM JOSH HOWE ON 2016-02-15
			//if($key == "OBKey__257_1" && $post != "") {
				//if($_POST['DocumentType'] != "SPECIALREADAGREEMENT") {
				//	$_POST['OBKey__121_1'] = $_POST['OBKey__257_1'];
				//	unset($_POST['OBKey__257_1']);
				//}
			//}
			$_POST[$key] = strtoupper(strip_tags($post));
		}

		//ADDED PER REQUEST FROM JOSH HOWE ON 2016-02-15
		if($_POST['OBKey__225_1'] == "") $_POST['OBKey__226_1'] = "";
		if($_POST['OBKey__225_2'] == "") $_POST['OBKey__226_2'] = "";
		if($_POST['OBKey__225_3'] == "") $_POST['OBKey__226_3'] = "";
		if($_POST['OBKey__225_4'] == "") $_POST['OBKey__226_4'] = "";
		if($_POST['OBKey__225_5'] == "") $_POST['OBKey__226_5'] = "";

		$Forms = new Forms($_POST);
	}
}


class Forms {

	//SETUP VARIABLES AND PATHS AND CALL FUNCTIONS DEPENDING ON THE REQUEST
	function __construct($vals = false) {
		$this->vals = $vals;
		$this->xml = simplexml_load_file(dirname(dirname(__FILE__)). "/forms.xml") or die("Error: Cannot create object");
		$this->ENCRYPTION_KEY = ENCRYPTION_KEY;
		$this->Valid_Counter = 0;

		//SPECIAL FIELDS
		if($this->vals['DocumentType'] == "SPECIALREADAGREEMENTCANCELLATION") {
			$this->vals['OBKey__188_1'] = date("m/d/Y",time());
		}
		if($this->vals['DocumentType'] == "SPECIALREADAGREEMENT") {
			$this->vals['OBKey__209_1'] = date("m/d/Y",time());
		}

		//IF THE REQUEST IS A NORMAL FORM SUBMISSION
		if($this->vals['DocumentType'] != "SUPPLEMENTARYDOCUMENT" && $this->vals['DocumentType'] != "") {
			$this->Get_Next_Conf_Number();
			$this->vals['Conf_Number'] = $this->Conf_Number;
			$this->Setup_Paths();
			if(isset($_FILES['Sup_File_1']['name']) && $_FILES['Sup_File_1']['name'] != "") {
				$this->Files = "";
				$this->Create_Supp_DIP($this->Validate_File_Uploads($_FILES));
			}

			//REMOVED SPECIAL READ AGREEMENT HTML CREATION PER JOSH ON 2016-02-15
			if($_POST['DocumentType'] != "SPECIALREADAGREEMENT") {
				$tmp = $this->Create_Form_HTML();
			}
			$this->Create_Form_DIP();
		}
		//IF THE REQUEST IS A SUPPLEMENTAL DOCUMENT SUBMISSION
		else if($this->vals['DocumentType'] == "SUPPLEMENTARYDOCUMENT" && isset($_FILES) && isset($this->vals['Conf_Number'])) {
			$this->Files = "";
			$this->Setup_Paths();
			$this->Create_Supp_DIP($this->Validate_File_Uploads($_FILES));
		}
		//IF THE REQUEST IS NEITHER A SUPPLEMENTAL DOCUMENT OR A NORMAL FORM SUBMISSION RETURN ERROR
		else if($this->vals['DocumentType'] != "") {
			exit("error");
		}
	}

	//GENERATE A NEW CONFIRMATION NUMBER
	//THIS FUNCTION IS NOT USED, IT WAS A TEST TO GENERATE A CONFIRMATION NUMBER OUTSIDE THE NORMAL PROCEDURE
	function Gen_Conf() {
		$this->Get_Next_Conf_Number();
		echo $this->Conf_Number;
	}

	function Setup_Paths() {
		//GET SCRIPT DIRECTORY
		$this->pwd = dirname(dirname(__FILE__));
		$this->path = "/mnt/onbase/";

		//CHANGE DEFAULT PATHS AND FILENAMES BELOW
		if(isset($this->vals['Conf_Number'])) {
			//SUPPLEMENTARY IMAGE FILES AND DIP FILES
			//supp DIP file name example: 20151204122913-000608-0382-supp.txt
			$supp_dip_filename = date("YmdHis",time()) . "-" . $this->vals['Conf_Number'] . "-supp.txt";
			$this->supp_dip_path = $this->path . $supp_dip_filename;

			//supp file name example: 20151204122913-000608-0382-img3.jpg
			$this->supp_image_file_name = date("YmdHis",time()) . "-" . $this->vals['Conf_Number'] . "-img";
			$this->supp_image_temp_path = $this->path;
		}

		//FORM DIP FILES
		//form DIP file example:20151204122846-000608-0382-form.txt
		$form_dip_filename = date("YmdHis",time()) . "-" . $this->Conf_Number . "-form.txt";
		$this->form_dip_path = $this->path . $form_dip_filename;

		//FORM HTML FILES
		//form HTML file example:20151204122846-000608-0382-html.html
		$this->form_html_filename = date("YmdHis",time()) . "-" . $this->Conf_Number . "-html.html";
		$this->form_html_path = $this->path . $this->form_html_filename;

		//FORM PDF FILES
		//form PDF file example:20151204122846-000608-0382-form.pdf
		$this->form_pdf_filename = date("YmdHis",time()) . "-" . $this->Conf_Number . "-form.pdf";
		$this->form_pdf_path = $this->path . $this->form_pdf_filename;
	}

	//ENCRYPT THE CONFIRMATION NUMBER USING THE PRIVATE KEY
	function encrypt($pure_string) {
		$iv_size = mcrypt_get_iv_size(MCRYPT_BLOWFISH, MCRYPT_MODE_ECB);
		$iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
		$encrypted_string = mcrypt_encrypt(MCRYPT_BLOWFISH, $this->ENCRYPTION_KEY, utf8_encode($pure_string), MCRYPT_MODE_ECB, $iv);
		return base64_encode($encrypted_string);
	}

	//DECRYPT THE ENCRYPTED CONFIRMATION NUMBER USING THE PRIVATE KEY
	function decrypt($encrypted_string) {
		$iv_size = mcrypt_get_iv_size(MCRYPT_BLOWFISH, MCRYPT_MODE_ECB);
		$iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);
		$decrypted_string = mcrypt_decrypt(MCRYPT_BLOWFISH, $this->ENCRYPTION_KEY, base64_decode($encrypted_string), MCRYPT_MODE_ECB, $iv);
		$decrypted_string = trim($decrypted_string, "\0");
		return $decrypted_string;
	}

	//VALIDATE FILE UPLOADS
	function Validate_File_Uploads($Files) {

		$counter = 0;
		foreach($Files as $File) {
			$counter++;
			//CHECK IF FILESIZES ARE TOO BIG
			if($File['size'] > 6291456) {
				$this->Files[$counter]['Response'] = "Error: Size";
			}
			//CHECK IF THE FILES ARE NOT THE CORRECT TYPE
			//REMOVED WORD DOCUMENTS PER JOSH REQUEST ON 2015-12-11
			// && substr($File['name'],strpos($File['name'],".")+1,3) != "doc"
			else if(explode("/",$File['type'])[0] != "image" && $File['type'] != "application/pdf") {
				$this->Files[$counter]['Response'] = "Error: Invalid";
			}
			else {
				$New_Name = $this->supp_image_file_name . $counter . "." . substr($File['name'],strpos($File['name'],".")+1);
				if(move_uploaded_file($File["tmp_name"], $this->supp_image_temp_path . $New_Name)) {
					$this->Files[$counter]['Response'] = "Success";
					$this->Files[$counter]['Filename'] = $New_Name;
					$this->Valid_Counter++;
				}
			}
			$this->Files[$counter]['Old_Filename'] = $File['name'];
			//REMOVE UPLOADED FILE FROM THE SERVER AND UNSET VARIABLE
			if(file_exists($File['tmp_name'])) {
				unlink($File['tmp_name']);
			}
			unset($File);
		}

	}

	//WRITE THE SUPPLEMENTARY DIP FILE
	function Create_Supp_DIP() {
		$line = "";
		$this->Message = "";
		foreach($this->Files as $counter => $val) {
			if($val['Filename'] != "") {
				$line .= str_pad("DocumentTypeNum:",30," ",STR_PAD_RIGHT) . "340\r\n";
				$line .= str_pad("Conf_Number:",30," ",STR_PAD_RIGHT) . $this->vals['Conf_Number'] . "\r\n";
				$line .= str_pad("SupplementaryType:",30," ",STR_PAD_RIGHT) . $this->vals['Sup_Type_'.$counter] . "\r\n";
				$line .= str_pad("Filename:",30," ",STR_PAD_RIGHT) . $val['Filename'] . "\r\n";
			}
			$this->Message .= "Message[" . $val['Old_Filename']. "]=" . $val['Response'] . "&";
		}
		$handle = fopen($this->supp_dip_path,"w");
		fwrite($handle,$line);
		fclose($handle);
		if(file_exists($this->supp_dip_path)) {
			if($this->vals['DocumentType'] == "SUPPLEMENTARYDOCUMENT") {
				header("Location: ../index.php?form=SuppConfirmation&Confirmation_Number=" . $this->vals['Conf_Number'] . "&" . $this->Message);
			}
		}
	}

	//GET NEXT CONFIRMATION NUMBER AND WRITE NEW CONFIRMATION NUMBER FOR NEXT REQUEST
	function Get_Next_Conf_Number() {
		$file = dirname(__FILE__) . "/confirmationsDO-NOT-DELETE.txt";
		$contents = trim(file_get_contents($file));
		if($contents != "") {
			$this->Conf_Number = $this->decrypt($contents);
			echo $this->Conf_Number;
			if(strlen($this->Conf_Number) == 6) {
				fwrite(fopen($file,"w"),$this->encrypt(str_pad(($this->Conf_Number + 1),6,"0",STR_PAD_LEFT)));
			}
			$this->Conf_Number = $this->Conf_Number . "-" . str_pad(rand(0,9999),4,"0",STR_PAD_LEFT);
		}
		else {
			//WRITE CONFIRMATION BACK TO FILE
			//$start = 2000;
			//fwrite(fopen($file,"w"),$this->encrypt(str_pad($start,6,"0",STR_PAD_LEFT)));
			exit("We're sorry, the request could not be completed. Please contact someone at the City of Bloomington Utilities at (812) 349-3930.<br /> <b>Error: </b>Could not get next confirmation number");
		}
	}

	//GET MAPPED NAME FROM XML FILE
	function Get_Mapped_Name($ob) {
		foreach($this->xml->form as $form) {
			if(strtoupper($form->file) == $this->vals['DocumentType']) {
				$this->Docs = $form->docs;
				foreach($form->fields as $val) {
					foreach($val as $field) {
						if($field->ob == $ob) {
							return $field->dip;
						}
					}
				}
				break(1);
			}
		}
	}

	//THIS FUNCTION IS NOT USED, IT WAS A TEST TO GENERATE PDF
	function Create_Form_PDF($tmp) {
		$cmd = "wkhtmltopdf " . $tmp . " " . $this->form_pdf_path;
		exec($cmd);

		if(file_exists($this->form_pdf_path)) {
			unlink($tmp);
		}
	}

	function Create_Form_HTML() {
		//GET THE FORM HTML AS THE CUSTOMER SEES IT (INCLUDING CSS AND JAVASCRIPT FILES) AND SAVE IT TO A TEMPORARY LOCATION
		$src = $this->pwd . "/forms/" . strtolower($_POST['DocumentType']) . ".html";
		$tmp = $this->pwd . "/temp/" . $this->form_html_filename;
		file_put_contents($tmp,file_get_contents("http://10.20.20.66/forms/index.php?form=" . strtolower($_POST['DocumentType'] . "&html=true")));

		$html = "";
		$lines = file($tmp);
		//START READING THE HTML FILE LINE BY LINE
		foreach($lines as $line_num => $line) {
			//MAKE MANUAL MODIFICATIONS TO THE WEB HTML VERSION TO BE COMPATIBLE WITH ONBASE VERSION
			if(strpos($line,"src=\"vendor")) {
				$line = str_replace("src=\"vendor",'src="\\\eureka\obdata$\Form_Tools\vendor',$line);
				$line = str_replace("assets/css/", "assets\css\\",$line);
				$line = str_replace("assets/js/", "assets\js\\",$line);
				$line = str_replace("assets/images/", "assets\images\\",$line);
				$line = str_replace("vendor/bootstrap/css/", "vendor\bootstrap\css\\",$line);
				$line = str_replace("vendor/bootstrap/js/", "vendor\bootstrap\js\\",$line);
				$line = str_replace("vendor/font-awesome/css/", "vendor\\font-awesome\css\\",$line);
				$line = str_replace("vendor/jquery/ui/", "vendor\jquery\ui\\",$line);
				$line = str_replace("vendor/jquery/", "vendor\jquery\\",$line);
				$line = str_replace("vendor/jquery-mask/", "vendor\jquery-mask\\",$line);
			}
			if(strpos($line,"src=\"assets")) {
				$line = str_replace("src=\"assets",'src="\\\eureka\obdata$\Form_Tools\assets',$line);
				$line = str_replace("assets/css/", "assets\css\\",$line);
				$line = str_replace("assets/js/", "assets\js\\",$line);
				$line = str_replace("assets/images/", "assets\images\\",$line);
				$line = str_replace("vendor/bootstrap/css/", "vendor\bootstrap\css\\",$line);
				$line = str_replace("vendor/bootstrap/js/", "vendor\bootstrap\js\\",$line);
				$line = str_replace("vendor/font-awesome/css/", "vendor\\font-awesome\css\\",$line);
				$line = str_replace("vendor/jquery/ui/", "vendor\jquery\ui\\",$line);
				$line = str_replace("vendor/jquery/", "vendor\jquery\\",$line);
				$line = str_replace("vendor/jquery-mask/", "vendor\jquery-mask\\",$line);
			}
			if(strpos($line,"href=\"vendor")) {
				$line = str_replace("href=\"vendor",'href="\\\eureka\obdata$\Form_Tools\vendor',$line);
				$line = str_replace("assets/css/", "assets\css\\",$line);
				$line = str_replace("assets/js/", "assets\js\\",$line);
				$line = str_replace("assets/images/", "assets\images\\",$line);
				$line = str_replace("vendor/bootstrap/css/", "vendor\bootstrap\css\\",$line);
				$line = str_replace("vendor/bootstrap/js/", "vendor\bootstrap\js\\",$line);
				$line = str_replace("vendor/font-awesome/css/", "vendor\\font-awesome\css\\",$line);
				$line = str_replace("vendor/jquery/ui/", "vendor\jquery\ui\\",$line);
				$line = str_replace("vendor/jquery/", "vendor\jquery\\",$line);
				$line = str_replace("vendor/jquery-mask/", "vendor\jquery-mask\\",$line);
			}
			if(strpos($line,"href=\"assets")) {
				$line = str_replace("href=\"assets",'href="\\\eureka\obdata$\Form_Tools\assets',$line);
				$line = str_replace("assets/css/", "assets\css\\",$line);
				$line = str_replace("assets/js/", "assets\js\\",$line);
				$line = str_replace("assets/images/", "assets\images\\",$line);
				$line = str_replace("vendor/bootstrap/css/", "vendor\bootstrap\css\\",$line);
				$line = str_replace("vendor/bootstrap/js/", "vendor\bootstrap\js\\",$line);
				$line = str_replace("vendor/font-awesome/css/", "vendor\\font-awesome\css\\",$line);
				$line = str_replace("vendor/jquery/ui/", "vendor\jquery\ui\\",$line);
				$line = str_replace("vendor/jquery/", "vendor\jquery\\",$line);
				$line = str_replace("vendor/jquery-mask/", "vendor\jquery-mask\\",$line);
			}
			if(strpos($line,"global.js")) {
				$line = str_replace("global.js","onbase.js",$line);
			}
			if(strpos($line,"Global = new Global;")) {
				$line = str_replace("Global = new Global;","",$line);
			}
			if(strpos($line,"Global.init();")) {
				$line = str_replace("Global.init();","init();",$line);
			}
			if(strpos($line,"dateTimeStamp") !== false) {
				$line = str_replace("name=\"dateTimeStamp\"","name=\"dateTimeStamp\" class=\"dateTimeStamp\" ",$line);
			}
			if(strpos($line,"service_row_hidden") !== false) {
				$line = str_replace("service_row_hidden","",$line);
			}
			if(strpos($line,"Add_More_Addresses") !== false) {
				$line = str_replace("Add_More_Addresses","Add_More_Addresses_hide",$line);
			}
			if(strpos($line,"global.css") !== false) {
				$line = str_replace("global.css","onbase.css",$line);
			}
			if(strpos($line,"enctype=\"multipart/form-data\"") !== false) {
				$line = str_replace("enctype=\"multipart/form-data\"","",$line);
			}


			$m = false;
			foreach($_POST as $name => $value) {
				//DETECT IF THE LINE INCLUDES THE FIELD ELEMENT ASSOCIATED WITH THE POSTED DATA, ADD THE VALUE TO THE FIELD, AND APPEND THE LINE
				if(strpos($line,"name=\"" . $name . "\"") !== false) {
					$attr = "";
					if(substr($name,0,5) != "OBKey") {
						$attr = "disabled";
					}
					if(strpos($line,"select") !== false) {
						$html .= substr_replace($line," " . $attr . " ", strpos($line,">"), 0);
						//$html .= $line;
						$html .= "<option selected value=\"" . $value . "\">" . $value . "</option>";
					}
					else if(strpos($line,"type=\"checkbox\"") !== false) {
						$html .= substr_replace($line, " " . $attr . " checked ", strpos($line,">"), 0);
					}
					else {
						$html .= substr_replace($line, " " . $attr . " value=\"" . $value . "\" ", strpos($line,">"), 0);
					}
					//SET MATCHED AS TRUE
					$m = true;
				}
			}
			if($m == false) {
				//APPEND THE LINE IF IT DOES NOT INCLUDE A FIELD ELEMENT
				if(strpos($line,"name=\"Agree\"") === false && strpos($line,"form-agree choose") === false) {
					$html .= $line;
				}
			}
		}
		//WRITE THE NEW HTML TO A FILE
		file_put_contents($this->form_html_path,$html);
		if(file_exists($this->form_html_path)) {
			//IF THE NEW FILE EXISTS, DELETE THE TEMP FILE
			unlink($tmp);
		}
		return $tmp;
	}

	//WRITE THE FORM DIP FILE
	function Create_Form_DIP() {
		$this->vals['Conf_Number'] = $this->Conf_Number;
		//ADD PER JOSH REQUEST ON 2016-02-17
		if($_POST['DocumentType'] != "SPECIALREADAGREEMENT") {
			$this->vals['Filename'] = $this->form_html_filename;
		}
		$line = "";
		foreach($this->vals as $key => $val) {
			$line .= str_pad($this->Get_Mapped_Name($key).":",30," ",STR_PAD_RIGHT) . $val . "\r\n";
		}
		$handle = fopen($this->form_dip_path,"w");
		fwrite($handle,$line);
		fclose($handle);
		if(file_exists($this->form_dip_path)) {
			$this->Docs = $this->Docs - $this->Valid_Counter;
			header("Location: ../index.php?form=Confirmation&Confirmation_Number=" . $this->Conf_Number . "&docs=" . $this->Docs . "&" . $Message);
		}
	}

}
