	<div class="form-header">		
		<div class="form-title logo"><img src="assets/images/logo.png"> City of Bloomington Utilities <img src="assets/images/logo.png"></div>
		<div class="description">
		</div>
		<div class="contact-info" style="font-size:14px; margin:5px; padding:5px; border:1px solid #315DA6; border-radius:25px; padding:10px; margin-bottom:25px;">
			<span style="font-weight:bold; font-size:16px; padding:5px;"><center>Customer Service Office Contact Information</center></span>
			<br />			
			<table class="table">
				<tr>
					<td>Operating Hours</td><td>8:00 am to 5:00 pm M-F</td>
				</tr>				
				<tr>
					<td>Address</td><td>600 E Miller Dr <br />Bloomington IN 47401</td>
				</tr>
				<tr>
					<td>Phone Number</td><td>(812) 349-3930</td>
				</tr>
				<tr>
					<td>Email Address</td><td><a href="mailto:utilities.cs@bloomington.in.gov">utilities.cs@bloomington.in.gov</td>
				</tr>
			</table>
		</div>
	</div>	

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
else {
	echo "<hr>";
	echo "<h3>Your application is being processed. If required, please upload further documentation by accessing this link:<br /><br />";
	echo "<a href=\"index.php?form=supplementary_docs&conf_num=" . $Confirmation_Number . "\">Upload Now</a>";
	echo "<hr>";
}

echo "<h3>You will be required to have the following confirmation number if you need to upload additional documents or if you need to contact a customer service representative at the City of Bloomington Utilities Department.";
echo "<h2>Your Confirmation Number is: <br /><b>" . $Confirmation_Number . "</b></h2>";
echo "<a target=\"_blank\" href=\"https://docs.google.com/a/bloomington.in.gov/forms/d/1sfKE7WKSkFAnGsB7UyVUGEkzAHWOFFeOTRmHH5MaY4k/viewform\">Provide feedback</a>";
echo "</center>";

//if(isset($_GET['Message'])) {
	//include("SuppConfirmation.php");
//}