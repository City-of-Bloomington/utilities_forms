<?php
include '../configuration.inc';
?>
<!-- saved from url=(0014)about:internet -->
<!DOCTYPE html>
<html lang="en">
	<head>
        <?php include '../template/head.inc'; ?>

		<script src="<?= BASE_URL; ?>/js/global.js"></script>
		<script type="text/javascript">
			Global = new Global;
			Global.init();

			function validateCaptcha() {
				Global.validateCaptcha();
			}
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

                        if (empty($_GET['html']) && requires_supps($name, $forms) > 0) {
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
