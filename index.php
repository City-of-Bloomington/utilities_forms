<?php
	error_reporting(0);
	header("Cache-Control: no-cache, no-store, must-revalidate");
	header("Pragma: no-cache");
	header("Expires: 0");
	?>
<!-- saved from url=(0016)http://localhost -->
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>City of Bloomington Utilities</title>
		<link rel="stylesheet" href="assets/css/global.css">
		<link rel="stylesheet" href="vendor/bootstrap/css/bootstrap.min.css">
		<link rel="stylesheet" href="vendor/font-awesome/css/font-awesome.min.css">
		<link rel="stylesheet" href="vendor/jquery/ui/jquery-ui.min.css">
		<script src="vendor/jquery/jquery-1.11.3.min.js"></script>
		<script src="vendor/jquery/ui/jquery-ui.min.js"></script>
		<script src="vendor/jquery-mask/jquery-mask.js"></script>
		<script src="vendor/bootstrap/js/bootstrap.min.js"></script>
		<script src="assets/js/global.js"></script>
		<script type="text/javascript">
			Global = new Global;
			Global.init();
		</script>
	</head>
	<body>
		<div id="Form_Container">
		<div class="container-fluid">
			<?php

				if (isset($_GET['form'])) {
					if (file_exists("forms/" . $_GET['form'] . ".html")) {
						//include("forms/" . $_GET['form'] . ".html");
						echo file_get_contents("forms/" . $_GET['form'] . ".html");
						if ($_GET['html'] != true && requires_supps($_GET['form']) > 0) {

							?>
							<script type="text/javascript">
								$(document).ready(function() {
									//$(".form-body").append("<h3>This form requires supplemental documents</h3>");
									setTimeout(function() {
										Global.Add_Supporting_Document_Upload();
									},10);
								})
							</script>
							<?php
							//include("forms/supplementary_docs.php");
						}
						//echo file_get_contents("forms/" . $_GET['form'] . ".html");
					}
					elseif (file_exists("forms/" . $_GET['form'] . ".php")) {
						include "forms/" . $_GET['form'] . ".php";
					}
				}
				else {
					$dir = "forms/";
					$files = scandir($dir);
					foreach ($files as $file) {
						if ($file !== "." && $file !== ".." && substr($file,-3,3) !== "php") {
							$form = substr($file,0,strpos($file,"."));
							echo "<a href=\"index.php?form=" . $form . "\">" . retrieve_form_name($form) . "</a><br />";
						}
					}
				}

				function requires_supps($form_) {
					$xml = simplexml_load_file("forms.xml") or die("Error: Cannot create object");
					foreach ($xml->form as $form) {
						if ($form->file === $form_) {
							return $form->docs;
						}
					}
				}

				function retrieve_form_name($form_) {
					$xml = simplexml_load_file("forms.xml") or die("Error: Cannot create object");
					foreach ($xml->form as $form) {
						if ($form->file === $form_) {
							return $form->name;
						}
					}
				}

			?>
			</div>
		</div>
	</body>
</html>
