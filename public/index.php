<?php
include '../configuration.inc';
?>
<!-- saved from url=(0016)http://localhost -->
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>City of Bloomington Utilities</title>
		<link rel="stylesheet" href="<?= BASE_URL; ?>/css/global.css">
		<link rel="stylesheet" href="<?= BASE_URL; ?>/vendor/bootstrap/css/bootstrap.min.css">
		<link rel="stylesheet" href="<?= BASE_URL; ?>/vendor/font-awesome/css/font-awesome.min.css">
		<link rel="stylesheet" href="<?= BASE_URL; ?>/vendor/jquery/ui/jquery-ui.min.css">
		<script src="<?= BASE_URL; ?>/vendor/jquery/jquery-1.11.3.min.js"></script>
		<script src="<?= BASE_URL; ?>/vendor/jquery/ui/jquery-ui.min.js"></script>
		<script src="<?= BASE_URL; ?>/vendor/jquery-mask/jquery-mask.js"></script>
		<script src="<?= BASE_URL; ?>/vendor/bootstrap/js/bootstrap.min.js"></script>
		<script src="<?= BASE_URL; ?>/js/global.js"></script>
		<script type="text/javascript">
			Global = new Global;
			Global.init();
		</script>
	</head>
	<body>
		<div id="Form_Container">
		<div class="container-fluid">
			<?php
                $forms = simplexml_load_file(APPLICATION_HOME.'/forms.xml');

                if (!empty($_GET['form'])) {
                    $name = preg_replace('/[^a-zA-Z\_]/', '', $_GET['form']);

                    if (file_exists(APPLICATION_HOME."/forms/$name.inc")) {
                        include     APPLICATION_HOME."/forms/$name.inc";

                        if (!empty($_GET['html']) && requires_supps($name, $forms) > 0) {
                            echo "
							<script type=\"text/javascript\">
								$(document).ready(function() {
									setTimeout(function() {
										Global.Add_Supporting_Document_Upload();
									},10);
								})
							</script>
							";
                        }
                    }
                }
				else {
                    echo '<ul>';
                    foreach ($forms->form as $form) {
                        $uri = BASE_URI.'/index.php?form='.$form->file;
                        echo "<li><a href=\"$uri\">{$form->name}</a></li>";
                    }
                    echo '</ul>';
				}

				function requires_supps($form_, $xml) {
					foreach ($xml->form as $form) {
						if ($form->file == $form_) {
							return (int)$form->docs;
						}
					}
				}
			?>
			</div>
		</div>
	</body>
</html>
