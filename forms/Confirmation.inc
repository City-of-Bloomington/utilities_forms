<div class="form-header">
<?php
    include __DIR__.'/partials/form-title-logo.inc';
    include __DIR__.'/partials/contact-info.inc';
?>
</div>

<?php

$Confirmation_Number = $_GET['Confirmation_Number'];
$docs = !empty($_GET['docs']) ? (int)$_GET['docs'] : 0;

$Nums = ["1"=>"ONE","2"=>"TWO","3"=>"THREE"];
$Error = 0;
$Success = 0;
$err_docs = "";
$suc_docs = "";
if (isset($_GET['Message'])) {
	foreach ($_GET['Message'] as $key => $Message) {
		if (substr($Message,0,5) == "Error") {
			$Error++;
			$err_docs = $err_docs . $key . ", ";
		}
		else {
			$Success++;
			$suc_docs = $suc_docs . $key . ", ";
		}
	}
	$err_docs = substr($err_docs,0,-2);
	$suc_docs = substr($suc_docs,0,-2);

	$Total = $Error + $Success;
}

echo "<center>";

if ($docs > 0 && $Error == 0) {
    $documents = $docs === 1 ? 'document' : 'documents';
	echo "
	<i class=\"fa fa-exclamation-triangle\" style=\"color:orange; font-size:120px;\"></i><br />
	<hr>
	<h3>This form requires $docs supplemental $documents.<br />
	<a style=\"line-height:35px;\" href=\"index.php?form=supplementary_docs&conf_num=$Confirmation_Number\">Upload Now</a>
	</h3>";
}
else if ($docs > 0 && $Error > 0) {
	echo "
	<center>
	<i class=\"fa fa-exclamation-triangle\" style=\"color:orange; font-size:120px;\"></i><br />
	<hr>
	<h3>Unfortunately, " . ($Total > 1 ? $Nums[$Error] . " of your documents (" . $err_docs . ") could not be uploaded" : "your document (" . $err_docs . ") could not be uploaded") . "</h3>
	<h4>(File sizes must be less than 6 MB and we are only able to accept PDF or image files)</h4>
	<h4><a href=\"index.php?form=supplementary_docs&conf_num=" . $_GET['Confirmation_Number'] . "\">Click here to try again</a></h4>
	<hr>
	</center>";
}
else {
	echo "
	<hr>
	<h3>Your application is being processed. You will be notified by a Customer Service Representative only if additional information is needed. If you are notified that additional information is needed, please upload documentation by accessing this link:<br /><br />
	<a href=\"index.php?form=supplementary_docs&conf_num=$Confirmation_Number\">Upload Now</a>
	</h3>";
}
?>
<br />
<p>You also have the option to upload your information by submitting a "Supplemental Document Upload Form" by accessing one directly from the main <a href="#">forms page</a></p>
<hr>
<h3>You will be required to have the following confirmation number if you need to upload additional documents or if you need to contact a customer service representative at the City of Bloomington Utilities Department.</h3>
<h2>Your Confirmation Number is: <br /><b><?= $Confirmation_Number; ?></b></h2>
<?php
   include __DIR__.'/partials/contact-info.inc';
?>
</center>
