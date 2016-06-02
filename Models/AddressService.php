<?php
/**
 * @copyright 2013-2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Application\Models;

use Blossom\Classes\Url;
include APPLICATION_HOME.'/Models/Url.php';

class AddressService
{
	/**
	 * @param string $query
	 * @return array
	 */
	public static function searchAddresses($query)
	{
		$results = [];
		if (defined('ADDRESS_SERVICE')) {
			$url = new Url(ADDRESS_SERVICE);
			$url->queryType = 'address';
			$url->format = 'json';
			$url->query = $query;

			$json = json_decode(Url::get($url));

			foreach ($json as $address) {
				$data = self::extractAddressData($address, self::parseAddress($query));
				$results[$data['location']] = $data;
			}
		}
		return $results;
	}

	/**
	 * @param string $address
	 * @return StdClass
	 */
	public static function parseAddress($address)
	{
		if (defined('ADDRESS_SERVICE')) {
			$url = new Url(ADDRESS_SERVICE.'/addresses/parse.php');
			$url->format = 'json';
			$url->address = $address;
			return json_decode(Url::get($url));
		}
	}

	/**
	 * @param StdClass $address       The address node
	 * @param array    $parsedAddress The parse of what the user typed
	 * @return array
	 */
	private static function extractAddressData($address, $parsedAddress)
	{
        $data = [
            'location' => $address->streetAddress,
            'addressId'=> $address->id,
            'city'     => $address->city,
            'state'    => $address->state,
            'zip'      => $address->zip,
            'latitude' => $address->latitude,
            'longitude'=> $address->longitude,
            'street_number_prefix' => $address->street_number_prefix,
            'street_number'        => $address->street_number,
            'street_number_suffix' => $address->street_number_suffix,
            'street_direction'     => $address->streetName->directionCode,
            'street_name'          => $address->streetName->name,
            'street_type'          => $address->streetName->typeCode,
            'street_postDirection' => $address->streetName->postDirectionCode
        ];

		// See if the user searched for a particular subunit
		if (isset($parsedAddress->subunitIdentifier) && isset($address->subunits)) {
            foreach ($address->subunits as $subunit) {
                if ($subunit->identifier == $parsedAddress->subunitIdentifier) {
                    $data['subunit_id'] = $subunit->identifier;
                    $data['location'  ] = "$data[location] {$subunit->type} {$subunit->identifier}";
                }
            }
		}
		// Include data for all subunits at this address
		else {
            if (isset($address->subunits)) {
                $data['subunits'] = $address->subunits;
            }
		}
		return $data;
	}


	public static function renderFormFields($index=1, $required=null)
	{
        $index    = (int)$index;
        $required = $required ? 'required="true"' : '';

        return "
        <button type=\"button\" onclick=\"ADDRESS_CHOOSER.launchPopup($index)\">
            Choose Address
        </button>
        <input id=\"OBKey__225_$index\" name=\"OBKey__225_$index\" $required address />
        <input id=\"OBKey__226_$index\" name=\"OBKey__226_$index\" $required />
        <input id=\"OBKey__104_$index\" name=\"OBKey__104_$index\" $required>
        ";
	}
}
