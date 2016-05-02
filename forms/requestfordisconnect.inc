<script type="text/javascript">
	$(document).ready(function() {

		$("#Date_of_Disconnect").datepicker({
			minDate: 0,
			maxDate: "+2M"
		});
	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="164">
	<input type="hidden" name="DocumentType" value="requestfordisconnect">

	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Request for Disconnect of Service and Final Bill</h2></div>
		<div class="description">
			<b>Request disconnection of services </b> (for residential and commercial customers)
		</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
            include __DIR__.'/partials/required-fields.inc';
        ?>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-6">
				<label for="Customer_Acct_Num">City of Bloomington Utilities Account Number</label>
				<input type="text" class="form-control" name="OBKey__125_1" id="Customer_Acct_Num" required spec>
			</div>
			<div class="col-xs-5">
				<label for="Date_of_Disconnect">Requested Date of Disconnection</label>
				<input meta="datetime" type="text" class="form-control" id="Date_of_Disconnect" required name="OBKey__229_1" mask="99/99/9999">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__137_1" id="First_Name" required>
			</div>
			<div class="col-xs-4">
				<label for="Middle_Name">Middle Name</label>
				<input type="text" class="form-control" name="Middle_Name" id="Middle_Name">
			</div>
			<div class="col-xs-3">
				<label for="Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__121_1" id="Last_Name" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Company_Name">Company Name </label>
				<input type="text" class="form-control" id="Company_Name" name="OBKey__257_1">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Email_Address">Email Address <br><span style="color:red;">(Please provide an email address to receive a confirmation email and status updates)</span></label>
				<input type="text" class="form-control" id="Email_Address" name="OBKey__393_1">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					<b style="">The service address is:</b>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-3">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_1" id="Service_St_Num" address required>
			</div>
			<div class="col-xs-2">
				<label for="Service_St_Dir">Street Dir.</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_1">
					<option value="" selected></option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
			</div>
			<div class="col-xs-6">
				<label for="Service_St_Name">Street Name/Unit</label>
				<input type="text" class="form-control" name="OBKey__104_1" id="Service_St_Name" required>
			</div>
		</div>
		<div class="row">

			<div class="col-xs-6">
				<label for="Telephone_Number">Telephone Number</label>
				<input type="text" class="form-control" name="Telephone_Number" id="Telephone_Number" phone mask="(999) 999-9999" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Mailing_Address">Permanent Address for Final Bill</label>
				<input type="text" class="form-control" name="Mailing_Address" id="Mailing_Address" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Mailing_City">City</label>
				<input type="text" class="form-control" name="Mailing_City" id="Mailing_City" required>
			</div>
			<div class="col-xs-4">
				<label for="Mailing_State">State</label>
				<input type="text" class="form-control" name="Mailing_State" id="Mailing_State" required>
			</div>
			<div class="col-xs-3">
				<label for="Mailing_Zipcode">ZIP Code</label>
				<input type="text" class="form-control" name="Mailing_Zipcode" id="Mailing_Zipcode" required numeric mask="99999">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Forwarding_Tel_Num">Forwarding Telephone Number</label>
				<input type="text" class="form-control" name="Forwarding_Tel_Num" id="Forwarding_Tel_Num" phone mask="(999) 999-9999" required>
			</div>
		</div>
	</div>

	<div class="form-footer">
		<div class="bottom-verbiage">
			<div class="row">
				<div class="col-xs-11">
					<div class="form-legal-text">
						If water service is disconnected (without a new signer) a service fee of $18.00 will appear on your final billing statement. If you have any additional questions, please contact customer service at (812) 349-3930.<br /><br /><b>* Aqua Pay customers: Final bills will NOT be automatically withdrawn from your bank account.</b>
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
						<input style="height:80px;" type="text" id="dateTimeStamp" name="dateTimeStamp" disabled readonly>
					</div>
				</div>
			</div>
		</div>
		<?php include APPLICATION_HOME.'/forms/partials/submit-fields.inc'; ?>
	</div>
</form>