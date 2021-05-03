<?php
require_once __DIR__.'/../bootstrap.php';

//CHECK CAPTCHA FIRST THING AND EXIT IF NOT VALID
if (!Application\Models\Captcha::verify()) {
    echo "You are clearly not human\n";
    exit();
}

//ENSURE THE CORRECT DATA IS PRESENT, MAKE UPPERCASE, AND REMOVE ANY TAGS IN THE POSTED DATA BEFORE CREATING THE FORM OBJECT
if (isset($_POST)) {
	if (count($_POST) > 1 && isset($_POST['DocumentType'])) {
		$_POST['dateTimeStamp'] = date("Y-m-d H:i:s",time());

		foreach ($_POST as $key => $post) {
			$_POST[$key] = strtoupper(strip_tags($post));
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

		$Forms = new Application\Models\Forms($_POST);
	}
}
