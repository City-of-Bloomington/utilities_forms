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
                    $url = "javascript:alert('$address')";

                    $city = isset($data['city']) ? ", $data[city]" : '';
                    echo "<li><a href=\"$url\">$address$city</a></li>";
                }
                echo '</ul>';
            }
        }
    ?>
</body>
</html>
