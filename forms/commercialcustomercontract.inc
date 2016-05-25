<script type="text/javascript">
	$(document).ready(function() {

		$("#Date_of_Change").datepicker({
			minDate: 0,
			maxDate: "+2M"
		});

		$("#Date_of_Inc").datepicker({
			changeMonth: true,
			changeYear: true,
			yearRange: "-150:-0",
			defaultDate: '01/01/1970'
		});

	})
</script>

<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="213">
	<input type="hidden" name="DocumentType" value="commercialcustomercontract">


	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Commercial Customer Contract</h2></div>
		<div class="description">
			<b>Sign up for water and sewer service.</b><br /> (for commercial customers)
		</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
            include __DIR__.'/partials/required-fields.inc';
        ?>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-11">
				<label for="Company_Name">Company Name</label>
				<input type="text" class="form-control" id="Company_Name" name="OBKey__257_1" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Company_CKA">Name most commonly known as</label>
				<input type="text" class="form-control" name="Company_CKA" id="Company_CKA">
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
				<label for="Service_St_Dir">St Dir</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_1" required>
					<option value="" selected></option>
					<option value="N/A">N/A</option>
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
			<div class="col-xs-4">
				<label for="City">City</label>
				<input type="text" class="form-control" name="City" id="City" readonly="readonly" value="Bloomington">
			</div>
			<div class="col-xs-4">
				<label for="State">State</label>
				<input type="text" class="form-control" name="State" id="State" readonly="readonly" value="IN">
			</div>
			<div class="col-xs-3">
				<label for="ZIP">ZIP</label>
				<input type="text" class="form-control" name="ZIP" id="ZIP" mask="99999">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Mailing_Name">Mail Attention Name</label>
				<input type="text" class="form-control" name="Mailing_Name" id="Mailing_Name">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Mailing_Address">Mailing Address</label><button class="btn btn-link" id="Auto_Fill_Mailing_Address">Same as above</button>
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
				<input type="text" class="form-control" name="Mailing_Zipcode" id="Mailing_Zipcode" mask="99999" numeric required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Email_Address">Email Address <br><span style="color:red;">(Please provide an email address to receive a confirmation email and status updates)</span></label>
				<input type="text" class="form-control" id="Email_Address" name="OBKey__393_1">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Date_of_Inc">Date of Incorporation</label>
				<input meta="datetime" type="text" class="form-control" id="Date_of_Inc" name="Date_of_Inc" mask="99/99/9999" required>
			</div>
			<div class="col-xs-5">
				<label for="State_of_Inc">State of Incorporation</label>
				<input type="text" class="form-control" name="State_of_Inc" id="State_of_Inc" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="Federal_ID">Federal ID</label>
				<input type="text" class="form-control" name="Federal_ID" id="Federal_ID" >
			</div>
			<div class="col-xs-6">
				<label for="Telephone_Number">Business Phone Number</label>
				<input type="text" class="form-control" name="Telephone_Number" id="Telephone_Number" mask="(999) 999-9999" phone required>
			</div>
		</div>

		<div class="row">
			<div class="col-xs-4">
				<label for="Contact_First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__137_1" id="Contact_First_Name" required>
			</div>
			<div class="col-xs-4">
				<label for="Contact_Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__121_1" id="Contact_Last_Name" required>
			</div>
			<div class="col-xs-3">
				<label for="Contact_Phone_Num">Contact Phone Number</label>
				<input type="text" class="form-control" name="Contact_Phone_Num" id="Contact_Phone_Num" mask="(999) 999-9999" phone required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="CommercialPerson">Occupancy type</label>
				<select name="Person" class="form-control" required id="CommercialPerson">
					<option value="">Please Select...</option>
					<option value="Owner">Property Owner</option>
					<option value="Tenant">Tenant</option>
					<option value="Other">Other - Please Explain</option>
				</select>
			</div>
			<div class="col-xs-6">
				<div class="hidden">
					<label for="Other_Explain">Please explain</label>
					<input type="text" class="form-control" name="Other_Explain" id="Other_Explain">
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Property_Owner">Name of the Property Owner</label>
				<input type="text" class="form-control" name="Property_Owner" id="Property_Owner" required>
			</div>
			<div class="col-xs-5">
				<label for="Owner_Phone_Number">Owner's Phone Number</label>
				<input type="text" class="form-control" name="Owner_Phone_Number" id="Owner_Phone_Number" mask="(999) 999-9999" required phone>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="Date_of_Change">&nbsp;<br />Requested Date of Change</label>
				<input control type="text" class="form-control" id="Date_of_Change" name="OBKey__173_1" mask="99/99/9999" required>
			</div>
			<div class="col-xs-6">
				<label for="Title">Title of individual signing for business or organization</label>
				<input type="text" class="form-control" name="Title" id="Title" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="New_Customer">Are you a new customer to City of Bloomington Utilities</label>
				<select name="New_Customer" class="form-control" style="width:100%;" id="New_Customer" required>
					<option value="">Please Select...</option>
					<option value="Yes">Yes</option>
					<option value="No">No</option>
				</select>
			</div>
			<div class="col-xs-6">
				<div class="hidden">
					<label for="Customer_Acct_Num">City of Bloomington Utilities Account Number</label>
					<input type="text" class="form-control" name="OBKey__125_1" id="Customer_Acct_Num" spec>
				</div>
			</div>

		</div>
		<div class="row">
			<div class="col-xs-11">
				<fieldset>
					<legend><label>Emergency Contact Information</label></legend>
					<div style="margin-bottom:8px; margin-top:8px;">
						In the Event of an emergency concerning your water and/or wastewater service, please provide us with the following emergency contact information.
					</div>
					<div class="col-xs-8">
						<label for="Emergency_Name">Emergency Name</label>
						<input type="text" class="form-control" id="Emergency_Name" name="Emergency_Name">
					</div>
					<div class="col-xs-4">
						<label for="Emergency_Phone">Phone Number</label>
						<input type="text" class="form-control" id="Emergency_Phone" name="Emergency_Phone" mask="(999) 999-9999" phone>
					</div>
				</fieldset>
			</div>
		</div>
	</div>

	<div class="form-footer">
		<div class="bottom-verbiage">
			<div class="row">
				<div class="col-xs-11">
					<div class="form-legal-text">
						I hereby contract with City of Bloomington Utilities (CBU) for service and agree to pay CBU for such service in accordance with its established rates. I also agree to conform to all CBU Rules, Regulations, and Standards of Service and applicable Indiana law, governing the user of water, wastewater, and stormwater, now in force or which may hereafter be adopted.
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
