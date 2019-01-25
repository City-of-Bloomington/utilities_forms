<?php
/**
 * @copyright 2013-2019 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
namespace Application\Models;

class AddressService
{
	public static function renderFormFields($index=1, $required=null, $multiple=false)
	{
        $index    = (int)$index;
        $required = ($required && $index == 1) ? 'required="true"' : '';
		$return   = "";

		if (!$multiple) {
			$return .= "
			<div class=\"row\">
				<button class=\"btn btn-link lookupAddress\" index=\"$index\">
					Lookup Address
				</button>
			</div>";
		}

		$return .= $multiple ? "" : "<div class=\"row\">";

		$return .= "
            <div class=\"col-xs-" . ($multiple ? "2" : "3") . "\">
				<label for=\"Service_St_Num\">St Num</label>
				<input index=\"$index\" class=\"form-control\" id=\"Service_St_Num\" name=\"OBKey__225_$index\" $required address readonly />
			</div>
			<div class=\"col-xs-2\">
				<label for=\"Service_St_Dir\">St Dir.</label>
				<input index=\"$index\" class=\"form-control\" id=\"Service_St_Dir\" name=\"OBKey__226_$index\" readonly />
			</div>
			<div class=\"col-xs-" . ($multiple ? "5" : "6") . "\">
				<label for=\"Service_St_Name\">Street Name/Unit</label>
				<input index=\"$index\" class=\"form-control\" id=\"Service_St_Name\" name=\"OBKey__104_$index\" $required readonly />
			</div>
        ";

        if ($multiple) {
            $return .= "
                <div class=\"col-xs-2\">
                    <span>&nbsp;<br /></span>
                    <div class=\"btn-group\">
                        <button title=\"Lookup Address\" class=\"btn btn-primary lookupAddress\" index=\"$index\"><i class=\"fa fa-search\"></i></button>
                    ";
                    if ($index == 1) {
                        $return .= "<button index=\"$index\" title=\"Add Another Address\" class=\"btn btn-success Add_More_Addresses\"><i class=\"fa fa-plus\"></i></button>";
                    }
                    if ($index < 6 && $index > 1) {
                        $return .= "<button index=\"$index\" title=\"Remove Address\" id=\"\" class=\"btn btn-danger Remove_Addresses\"><i class=\"fa fa-remove\"></i></button>";
                    }
            $return .= "
                    </div>
                </div>";
        }

		$return .= $multiple ? "" : "</div>";
		return $return;
	}
}
