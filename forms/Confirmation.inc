<div class="form-header">
<?php
    include __DIR__.'/partials/form-title-logo.inc';
    include __DIR__.'/partials/contact-info.inc';
?>
</div>

<?php

$Confirmation_Number = $_GET['Confirmation_Number'];
$docs = !empty($_GET['docs']) ? (int)$_GET['docs'] : 0;

echo "<center>";

if ($docs) {
    $documents = $docs === 1 ? 'document' : 'documents';
	echo "
	<i class=\"fa fa-exclamation-triangle\" style=\"color:orange; font-size:120px;\"></i><br />
	<hr>
	<h3>This form requires $docs supplemental $documents.<br />
	<a style=\"line-height:35px;\" href=\"index.php?form=supplementary_docs&conf_num=$Confirmation_Number\">Upload Now</a>
	<hr>
	";
}
else {
	echo "
	<hr>
	<h3>Your application is being processed. If notified by a Customer Service Representative, please upload further documentation by accessing this link:<br /><br />
	<a href=\"index.php?form=supplementary_docs&conf_num=$Confirmation_Number\">Upload Now</a>
	<hr>
	";
}
?>
<h3>You will be required to have the following confirmation number if you need to upload additional documents or if you need to contact a customer service representative at the City of Bloomington Utilities Department.
<h2>Your Confirmation Number is: <br /><b><?= $Confirmation_Number; ?></b></h2>
<a target="_blank" href="https://docs.google.com/a/bloomington.in.gov/forms/d/1sfKE7WKSkFAnGsB7UyVUGEkzAHWOFFeOTRmHH5MaY4k/viewform">Provide feedback</a>
</center>
