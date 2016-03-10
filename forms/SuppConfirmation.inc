	<div class="form-header">
		<div class="form-title">City of Bloomington Utilities</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
        ?>
	</div>
<script type="text/javascript">
	var url = window.location.toString().split("?")[0];
	window.history.replaceState('', '', url + '?form=SuppConfirmation');
</script>
<?php
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

	if ($Error > 0) {
		echo "<center>";
		echo "<i class=\"fa fa-exclamation-triangle\" style=\"color:orange; font-size:120px;\"></i><br />";
		echo "<hr>";
		echo "<h3>Unfortunately, " . ($Total > 1 ? $Nums[$Error] . " of your documents (" . $err_docs . ") could not be uploaded" : "your document (" . $err_docs . ") could not be uploaded") . "</h3>";
		echo "<h4>(File sizes must be less than 6 MB and we are only able to accept PDF or image files)</h4>";
		echo "<h4><a href=\"index.php?form=supplementary_docs&conf_num=" . $_GET['Confirmation_Number'] . "\">Click here to try again</a></h4>";
		echo "<hr>";
		echo "</center>";
	}
	if ($Success > 0) {
		echo "<h3>" . ($Total > 1 ? $Nums[$Success] . " of your documents (" . $suc_docs . ") has been uploaded successfully" : "Your document (" . $suc_docs . ") was uploaded successfully") . "</h3>";
	}
}
else {

}