<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
require_once '../configuration.inc';
require_once APPLICATION_HOME.'/public/forms.processor.php';

class FormsTest extends PHPUnit_Framework_TestCase
{
	public function namesProvider()
	{
		return [
            [['DocumentType'=>'AQUAPAY',    'ob'=>'OBKey__137_1'], ['docs'=>'0', 'dip'=>'First_Name']],
            [['DocumentType'=>'AQUAPAY',    'ob'=>'Phone_Number'], ['docs'=>'0', 'dip'=>'Phone_Number']],
            [['DocumentType'=>'AQUAPAY',    'ob'=>'OBKey__125_1'], ['docs'=>'0', 'dip'=>'Customer_Acct_Num']],
            [['DocumentType'=>'NAMECHANGE', 'ob'=>'OBKey__393_1'], ['docs'=>'1', 'dip'=>'Email_Address']],
            [['DocumentType'=>'NAMECHANGE', 'ob'=>'OBKey__226_1'], ['docs'=>'1', 'dip'=>'Service_St_Dir']],
            [['DocumentType'=>'NAMECHANGE', 'ob'=>'OBKey__125_1'], ['docs'=>'1', 'dip'=>'Customer_Acct_Num']]
		];
    }
    
	/**
	 * @dataProvider namesProvider
	 */
    public function testMappedNames($input, $output)
    {
        $value = Forms::Get_Mapped_Name($input);
        $this->assertEquals($output, $value);
    }
}