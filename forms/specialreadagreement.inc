<script type="text/javascript">
	$(document).ready(function() {


	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="341">
	<input type="hidden" name="DocumentType" value="specialreadagreement">

	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Special Read Agreement</h2></div>
		<div class="description">
		<!-- REMOVED PER JOSH REQUEST ON 2016-02-15
			Are you a property owner who would like utilities to revert to your name when tenants move out? Sign up for a special read agreement, and we'll keep it on file so you will never have to worry about service disconnection in between tenants.
		-->
		</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
            include __DIR__.'/partials/required-fields.inc';
        ?>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-8">
				<label for="Customer_Acct_Num">City of Bloomington Utilities Account Number</label>
				<input type="text" class="form-control" name="OBKey__125_1" id="Customer_Acct_Num" spec>
			</div>
		</div>

		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					Anytime a current customer moves from
				</div>
			</div>
		</div>
		<div class="row service_row service_row_first">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_1" id="Service_St_Num" numeric required>
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_1">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>

				<!--<input type="text" class="form-control" name="OBKey__226_1" id="Service_St_Dir" value="N/A">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_1" id="Service_St_Name" required>
			</div>
			<div class="col-xs-2">
			<span>&nbsp;<br /></span>
				<button id="Add_More_Addresses" class="btn btn-success"><i class="fa fa-plus"></i> Add</button>
			</div>
		</div>
		<div class="row service_row service_row_hidden">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_2" id="Service_St_Num" numeric>
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_2">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
				<!--<input type="text" class="form-control" name="OBKey__226_2" id="Service_St_Dir">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_2" id="Service_St_Name">
			</div>
			<div class="col-xs-2">
			<span>&nbsp;<br /></span>
				<button id="Add_More_Addresses" class="btn btn-success"><i class="fa fa-plus"></i> Add</button>
			</div>
		</div>
		<div class="row service_row service_row_hidden">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_3" id="Service_St_Num" numeric>
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_3">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
				<!--<input type="text" class="form-control" name="OBKey__226_3" id="Service_St_Dir">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_3" id="Service_St_Name">
			</div>
			<div class="col-xs-2">
			<span>&nbsp;<br /></span>
				<button id="Add_More_Addresses" class="btn btn-success"><i class="fa fa-plus"></i> Add</button>
			</div>
		</div>
		<div class="row service_row service_row_hidden">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_4" id="Service_St_Num" numeric>
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_4">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
				<!--<input type="text" class="form-control" name="OBKey__226_4" id="Service_St_Dir">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_4" id="Service_St_Name">
			</div>
			<div class="col-xs-2">
			<span>&nbsp;<br /></span>
				<button id="Add_More_Addresses" class="btn btn-success"><i class="fa fa-plus"></i> Add</button>
			</div>
		</div>
		<div class="row service_row service_row_hidden">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_5" id="Service_St_Num" numeric>
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_5">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
				<!--<input type="text" class="form-control" name="OBKey__226_5" id="Service_St_Dir">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_5" id="Service_St_Name">
			</div>
			<div class="col-xs-2">
			<span>&nbsp;<br /></span>

			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					I authorize City of Bloomington Utilities (CBU) to transfer the water/sewer service into the name of:
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__137_1" id="First_Name" required>
			</div>
			<div class="col-xs-3">
				<label for="Middle_Name">Middle Name</label>
				<input type="text" class="form-control" name="OBKey__156_1" id="Middle_Name">
			</div>
			<div class="col-xs-4">
				<label for="Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__121_1" id="Last_Name" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Company_Name">Customer Name </label>
				<input type="text" class="form-control" id="Company_Name" name="OBKey__257_1">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-7">
				<label for="Email_Address">Email Address</label>
				<input type="text" class="form-control" id="Email_Address" name="OBKey__393_1" required>
			</div>
			<div class="col-xs-4">
				<label for="Telephone_Number">Telephone Number</label>
				<input type="text" class="form-control" name="OBKey__383_1" id="Telephone_Number" required phone mask="(999) 999-9999">
			</div>
		</div>

		<div class="row">
			<div class="col-xs-11">
				<label for="Mailing_Address">Mailing Address</label>
				<input type="text" class="form-control" name="OBKey__398_1" id="Mailing_Address" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Mailing_City">City</label>
				<input type="text" class="form-control" name="OBKey__394_1" id="Mailing_City" required value="Bloomington">
			</div>
			<div class="col-xs-4">
				<label for="Mailing_State">State</label>
				<input type="text" class="form-control" name="OBKey__401_1" id="Mailing_State" required value="IN">
			</div>
			<div class="col-xs-3">
				<label for="Mailing_Zipcode">ZIP Code</label>
				<input type="text" class="form-control" name="OBKey__405_1" id="Mailing_Zipcode" required mask="99999" numeric>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					The owner is
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Owner_First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__390_1" required id="Owner_First_Name">
			</div>
			<div class="col-xs-4">
				<label for="Owner_Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__388_1" required id="Owner_Last_Name">
			</div>
			<div class="col-xs-3">
				<label for="Owner_Title">Title</label>
				<input type="text" class="form-control" name="OBKey__112_1" id="Owner_Title">
			</div>
		</div>
	</div>

	<div class="form-footer">
		<div class="bottom-verbiage">
			<div class="row">
				<div class="col-xs-11">
					<div class="form-legal-text">
						I, (or the firm I represent) acknowledge that I, (or the firm I represent) will be responsible for all water/sewer bills incurred for the property when service has been transferred according to this agreement, regardless of the amount of the bill. I agree to notify CBU if the property changes ownership or if the agreement should be voided for any reason.<br /><br />I understand and acknowledge that this agreement will be voided if the landowner or property manager asks to have the water/sewer turned off at any time, and that a reconnection fee would be charged if the water/sewer is turned back on.

					</div>
				</div>
			</div>
			<div class="row">
				<div class="col-xs-11">
					<div class="form-legal-text">I affirm that the information contained herein, including attachment(s), is complete and accurate.</div>
				</div>
			</div>
			<div class="row" style="height:80px;">
				<div class="col-xs-5">
					<div class="form-legal-input">
						<div class="checkbox" style="display:none;">
							<input id="Agree" name="Agree" type="checkbox" value="Yes"> I Agree
						</div>
						<div class="form-agree choose"><i class=""></i> <span>Click if you Agree</span></div>
					</div>
				</div>
				<div class="col-xs-6">
					<div class="form-legal-input">
						<input style="height:80px;" type="text" id="dateTimeStamp" name="dateTimeStamp" readonly>
					</div>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-2"></div>
			<div class="col-xs-7">
				<center>
					<button type="submit" name="OBBtn_Save" value="Submit" class="btn btn-primary" id="form-submit" disabled><i class="fa fa-check"></i> Submit</button>
				</center>
			</div>
			<div class="col-xs-2"></div>
		</div>
	</div>
</form>