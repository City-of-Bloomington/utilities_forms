<script type="text/javascript">
	$(document).ready(function() {

		$("#Date_of_Change").datepicker({
			minDate: 1,
			beforeShowDay: $.datepicker.noWeekends
		});

		$("#Date_of_Birth").datepicker({
			changeMonth: true,
			changeYear: true,
			yearRange: "-100:-18",
			defaultDate: '01/01/1970'
		});
	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="162">
	<input type="hidden" name="DocumentType" value="individualcustomercontract">


	<div class="form-header">
		<div class="form-title logo"><center><img src="assets/images/logo.png"> City of Bloomington Utilities <img src="assets/images/logo.png"></center></div>
		<div class="form-title"><h2>Individual Customer Contract</h2></div>
		<div class="description">
			<b>Sign up for water and sewer service</b> (for residential customers). You will need an acceptable form of identification to attach as a file to this service application, and a copy of your lease, if applicable.
		</div>
		<div class="contact-info" style="font-size:14px; margin:5px; padding:5px; border:1px solid #315DA6; border-radius:25px; padding:10px; margin-bottom:25px;">
			<span style="font-weight:bold; font-size:16px; padding:5px;"><center>Customer Service Office Contact Information</center></span>
			<br />
			<table class="table">
				<tr>
					<td>Operating Hours</td><td>8:00 am to 5:00 pm M-F</td>
				</tr>
				<tr>
					<td>Address</td><td>600 E Miller Dr <br />Bloomington IN 47401</td>
				</tr>
				<tr>
					<td>Phone Number</td><td>(812) 349-3930</td>
				</tr>
				<tr>
					<td>Email Address</td><td><a href="mailto:utilities.cs@bloomington.in.gov">utilities.cs@bloomington.in.gov</td>
				</tr>
			</table>
		</div>
		<div><req>*</req> <b>Field is Required</b></div>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-4">
				<label for="First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__137_1" id="First_Name" required>
			</div>
			<div class="col-xs-3">
				<label for="Middle_Name">Middle Name</label>
				<input type="text" class="form-control" name="Middle_Name" id="Middle_Name" placeholder="">
			</div>
			<div class="col-xs-4">
				<label for="Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__121_1" id="Last_Name" required>
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
			<div class="col-xs-4">
				<label for="Service_St_Num">Street Number</label>
				<input type="text" class="form-control" name="OBKey__225_1" id="Service_St_Num" numeric required>
			</div>
			<div class="col-xs-4">
				<label for="Service_St_Dir">Street Direction</label>
				<select id="Service_St_Dir" class="form-control" name="OBKey__226_1">
					<option value="N/A" selected>N/A</option>
					<option value="N">N</option>
					<option value="E">E</option>
					<option value="S">S</option>
					<option value="W">W</option>
				</select>
				<!--<input type="text" class="form-control" name="OBKey__226_1" id="Service_St_Dir">-->
			</div>
			<div class="col-xs-3">
				<label for="Service_St_Name">Street Name</label>
				<input type="text" class="form-control" name="OBKey__104_1" id="Service_St_Name" required>
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
				<label for="Mailing_Address">Mailing Address</label><button class="btn btn-link" id="Auto_Fill_Mailing_Address">Same as above</button>
				<input type="text" class="form-control" name="OBKey__398_1" id="Mailing_Address">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Mailing_City">City</label>
				<input type="text" class="form-control" name="OBKey__394_1" id="Mailing_City" value="Bloomington">
			</div>
			<div class="col-xs-4">
				<label for="Mailing_State">State</label>
				<input type="text" class="form-control" name="OBKey__401_1" id="Mailing_State" value="IN">
			</div>
			<div class="col-xs-3">
				<label for="Mailing_Zipcode">ZIP Code</label>
				<input type="text" class="form-control" name="OBKey__405_1" id="Mailing_Zipcode" numeric mask="99999">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Date_of_Birth">Date of Birth</label>
				<input meta="datetime" type="text" class="form-control" id="Date_of_Birth" name="Date_of_Birth" mask="99/99/9999" required>
			</div>
			<div class="col-xs-3">
				<label for="Soc_Sec_Num">Social Security Number</label>
				<input type="text" class="form-control" name="Soc_Sec_Num" mask="999-99-9999" id="Soc_Sec_Num" ssn numeric>
			</div>
			<div class="col-xs-4">
				<label for="Telephone_Number">Telephone Number</label>
				<input type="text" class="form-control" name="OBKey__383_1" id="Telephone_Number" mask="(999) 999-9999" phone required>
			</div>

		</div>
		<div class="row">
			<!--
			<div class="col-xs-6">
				<label for="ID_Type">Identification Type</label>
				<select class="form-control" name="ID_Type" validate="true" id="ID_Type">
					<option value="">Please Select...</option>
					<option value="Drivers License">Drivers License</option>
					<option value="State ID">State Issued ID</option>
					<option value="School ID">School ID</option>
					<option value="Military ID">Military ID</option>
					<option value="Passport">Passport</option>
					<option value="Visa">Visa</option>
					<option value="Other">Other</option></select>
			</div>
			-->
			<div class="col-xs-6">
				<label for="ID_Number_Num">Identification Number</label>
				<input type="text" class="form-control" name="ID_Number_Num" id="ID_Number_Num">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="IndividualPerson">Occupancy type</label>
				<select name="Person" class="form-control" id="IndividualPerson" required>
					<option value="">Please Select...</option>
					<option value="Owner">Property Owner</option>
					<option value="Tenant">Tenant</option>
					<option value="Other">Other - Please Explain</option>
				</select>
			</div>
			<div class="col-xs-5">
				<div class="hidden">
					<label for="Other_Explain">Please explain</label>
					<input type="text" class="form-control" id="Other_Explain" name="Other_Explain">
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Property_Owner">Name of the Property Owner</label>
				<input type="text" class="form-control" id="Property_Owner" name="Property_Owner">
			</div>
			<div class="col-xs-5">
				<label for="Owner_Phone_Number">Owner's Phone Number</label>
				<input type="text" class="form-control" id="Owner_Phone_Number" name="Owner_Phone_Number" mask="(999) 999-9999" phone required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Employers_Name">Employer's Name</label>
				<input type="text" class="form-control" id="Employers_Name" name="Employers_Name">
			</div>
			<div class="col-xs-5">
				<label for="Employers_Ph_Num">Employer's Phone Number</label>
				<input type="text" class="form-control" id="Employers_Ph_Num" name="Employers_Ph_Num" mask="(999) 999-9999" phone>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-8">
				<label for="Date_of_Change">Requested Date of Change <br />(Please select a date after today and Monday - Friday)</label>
				<input type="text" class="form-control" id="Date_of_Change" name="OBKey__173_1" required mask="99/99/9999">
			</div>

		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="New_Customer">Are you a new customer to City of Bloomington Utilities</label>
				<select name="New_Customer" class="form-control" id="New_Customer" style="" required>
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
					<div class="col-xs-7">
						<label for="Emergency_Name">Name</label>
						<input type="text" class="form-control" id="Emergency_Name" name="Emergency_Name">
					</div>
					<div class="col-xs-5">
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
					<div class="form-legal-text">I affirm that the information contained herein, including attachment(s), is complete and accurate.</div>
				</div>
			</div>
			<div class="row">
				<div class="col-xs-6">
					<div class="form-legal-input">
						<div class="checkbox" style="display:none;">
							<input id="Agree" name="Agree" type="checkbox" value="Yes"> I Agree
						</div>
						<div class="form-agree choose"><i class=""></i> <span>Click if you Agree</span></div>
					</div>
				</div>
				<div class="col-xs-5">
					<div class="form-legal-input">
						<input style="height:80px;" type="text" id="dateTimeStamp" name="dateTimeStamp" disabled readonly>
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