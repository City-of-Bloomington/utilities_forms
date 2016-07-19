<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
include '../configuration.inc';

$query = !empty($_GET['query'])
    ? htmlspecialchars(trim(urldecode($_GET['query'])), ENT_QUOTES, 'UTF-8')
    : '';
?>
<!DOCTYPE html>
<html lang="en">
<body>
    <form method="get">
        <fieldset><legend>Find an address</legend>
			<div class="form-inline">
				<div class="form-group">
					<input style="width:425px;" class="form-control" name="query" value="<?= $query ?>" />
					<button id="searchAddress" class="btn btn-primary">
						<i class="fa fa-search"></i>
						Search 
					</button>
				</div>
			</div>
        </fieldset>
    </form>
	<div style="width:550px;height:260px;overflow:auto;">
    <?php
        if (!empty($_GET['query'])) {
            $results = Application\Models\AddressService::searchAddresses($_GET['query']);
            if (count($results)) {
				
					echo '<table class="table table-striped">';
					foreach ($results as $address => $data) {
						$number = '';
						$number.= $data['street_number_prefix'] ? $data['street_number_prefix'].' ' : '';
						$number.= $data['street_number'];
						$number.= $data['street_number_suffix'] ? ' '.$data['street_number_suffix'] : '';

						$number = htmlspecialchars($number, ENT_QUOTES);

						$direction = $data['street_direction'] ? $data['street_direction'] : '';
						$direction = strtoupper($direction);

						$name = "$data[street_name] $data[street_type]";
						$name.= $data['street_postDirection'] ? ' '.$data['street_postDirection'] : '';
						$name = htmlspecialchars($name, ENT_QUOTES);
						$name = strtoupper($name);						

						$url = "javascript:self.ADDRESS_CHOOSER.setAddress('$number', '$direction', '$name')";

						$city = isset($data['city']) ? ", $data[city]" : '';
						echo "<tr><td><a href=\"$url\">$address$city</a></td></tr>";
						if (!empty($data['subunits'])) {
							foreach ($data['subunits'] as $s) {
								$subname = "{$s->type} {$s->identifier}";
								$subname = strtoupper($subname);
								$url = "javascript:self.ADDRESS_CHOOSER.setAddress('$number', '$direction', '$name $subname')";
								echo "<tr><td><a href=\"$url\">$address $subname$city</a></td></tr>";
							}
						}
					}
					echo '</table>';
				
            }
			else {
				echo "<center><h4>No Results</h4></center>";
			}
        }
    ?>
	</div>
</body>
</html>
