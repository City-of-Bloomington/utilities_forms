<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
include '../configuration.inc';

$query = !empty($_GET['query'])
    ? htmlspecialchars(trim($_GET['query']), ENT_QUOTES, 'UTF-8')
    : '';
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <?php include '../template/head.inc'; ?>
</head>
<body>
    <form method="get">
        <fieldset><legend>Find an address</legend>
            <label>
                <input name="query" value="<?= $query; ?>" />
            </label>
            <button type="submit" class="btn btn-primary">
                <i class="fa fa-search"></i>
                Search
            </button>

        </fieldset>
    </form>
    <?php
        if (!empty($_GET['query'])) {
            $results = Application\Models\AddressService::searchAddresses($_GET['query']);
            if (count($results)) {
                echo '<ul>';
                foreach ($results as $address => $data) {
                    $number = '';
                    $number.= $data['street_number_prefix'] ? $data['street_number_prefix'].' ' : '';
                    $number.= $data['street_number'];
                    $number.= $data['street_number_suffix'] ? ' '.$data['street_number_suffix'] : '';

                    $number = htmlspecialchars($number, ENT_QUOTES);

                    $direction = $data['street_direction'] ? $data['street_direction'] : '';

                    $name = "$data[street_name] $data[street_type]";
                    $name.= $data['street_postDirection'] ? ' '.$data['street_postDirection'] : '';
                    $name = htmlspecialchars($name, ENT_QUOTES);

                    $url = "javascript:self.opener.ADDRESS_CHOOSER.setAddress('$number', '$direction', '$name')";

                    $city = isset($data['city']) ? ", $data[city]" : '';
                    echo "<li><a href=\"$url\">$address$city</a></li>";
                    if ($data['subunits']) {
                        echo '<ul>';
                        foreach ($data['subunits'] as $s) {
                            $subname = "{$s->type} {$s->identifier}";
                            $url = "javascript:self.opener.ADDRESS_CHOOSER.setAddress('$number', '$direction', '$name $subname')";
                            echo "<li><a href=\"$url\">$address $subname$city</a></li>";
                        }
                        echo '</ul>';
                    }
                }
                echo '</ul>';
            }
        }
    ?>
</body>
</html>
