<?php

$Confirmation_Number = $_GET['Confirmation_Number'];
$docs = $_GET['docs'];

echo "<center>";

if($docs != "0") {
	echo "<i class=\"fa fa-exclamation-triangle\" style=\"color:orange; font-size:120px;\"></i><br />";	
	echo "<hr>";
	echo "<h3>This form requires " . $docs . " supplemental " . ($docs == 1 ? "document" : "documents") . ".<br />";
	echo "<a style=\"line-height:35px;\" href=\"index.php?form=supplementary_docs&conf_num=" . $Confirmation_Number . "\">Upload Now</a>";
	echo "<hr>";
}

echo "<h3>You will require the following confirmation number if you need to upload additional documents or if you need to contact someone at the City of Bloomington Utilities Department.";
echo "<h2>Your Confirmation Number is: <br /><b>" . $Confirmation_Number . "</b></h2>";
echo "</center>";

//if(isset($_GET['Message'])) {
	//include("SuppConfirmation.php");
//}