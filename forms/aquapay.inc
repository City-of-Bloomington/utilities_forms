<script type="text/javascript">
	$(document).ready(function() {

		$("#Date_of_Inc").datepicker({
			changeMonth: true,
			changeYear: true,
			yearRange: "-100:-18",
			defaultDate: '01/01/1970'
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
	<input type="hidden" name="DocumentTypeNum" value="170">
	<input type="hidden" name="DocumentType" value="aquapay">

	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Authorization Agreement for Preauthorized Payments</h2></div>
		<div class="description">
			<b>Sign up for automatic payments </b>from either your checking or savings account. Your balance due will be automatically drawn each month on the due date of your bill. You will still receive a bill in the mail (or by e-mail for <a href="https://esuite.bloomington.in.gov/eSuite.Utilities/Default.aspx?ReturnUrl=%2Fesuite.utilities%2F">E-Bill</a> customers) for your records showing the charges each month, but once enrolled you will never need to write a check to us again!
		</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
            include __DIR__.'/partials/required-fields.inc';
        ?>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-4">
				<label for="First_Name">First Name</label>
				<input type="text" class="form-control" id="First_Name" name="OBKey__137_1" required>
			</div>
			<div class="col-xs-3">
				<label for="Middle_Name">Middle Name</label>
				<input type="text" class="form-control" id="Middle_Name" name="Middle_Name">
			</div>
			<div class="col-xs-4">
				<label for="Last_Name">Last Name </label>
				<input type="text" class="form-control" id="Last_Name" name="OBKey__121_1" required>
			</div>
		</div>


		<div class="row">
			<div class="col-xs-11">
				<label for="Email_Address">Email Address <br><span style="color:red;">(Please provide an email address to receive a confirmation email and status updates)</span></label>
				<input type="text" class="form-control" id="Email_Address" name="OBKey__393_1">
			</div>
		</div>
		<div class="row">

			<div class="col-xs-5">
				<label for="Phone_Number">Phone Number</label>
				<input type="text" class="form-control" id="Phone_Number" name="Phone_Number" mask="(999) 999-9999" required>
			</div>
			<div class="col-xs-6">
				<label for="Customer_Acct_Num">City of Bloomington Utilities Account Number</label>
				<input type="text" class="form-control" id="Customer_Acct_Num" name="OBKey__125_1" spec>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					<b style="">The service address is:</b>
				</div>
			</div>
		</div>

            <?= Application\Models\AddressService::renderFormFields(1,true); ?>

		<hr>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					<b style="">If completing this form as an individual please complete the following.</b>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="Date_of_Birth">&nbsp;<br>Date of Birth</label>
				<input meta="datetime" type="text" class="form-control" id="Date_of_Birth" id="Date_of_Birth" name="Date_of_Birth" mask="99/99/9999">
			</div>
		</div>
		<hr>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					<b style="">If completing this form as a company please complete the following.</b>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Company_Name">Company Name </label>
				<input type="text" class="form-control" id="Company_Name" name="OBKey__257_1">
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Customer_Fed_TIN">Business Customer's Federal TIN</label>
				<input type="text" class="form-control" id="Customer_Fed_TIN" name="Customer_Fed_TIN" numeric >
			</div>
			<div class="col-xs-5">
				<label for="Date_of_Inc">Date of Incorporation</label>
				<input meta="datetime" type="text" class="form-control" id="Date_of_Inc" name="Date_of_Inc" mask="99/99/9999">
			</div>
		</div>
		<hr>
		<div class="row">
			<div class="col-xs-11">
				<label for="Name_of_Fin_Inst">Name of your Financial Institution </label>
				<input type="text" class="form-control" id="Name_of_Fin_Inst" name="Name_of_Fin_Inst"  required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-4">
				<label for="Routing_Number">Routing Number </label>
				<input type="text" class="form-control" id="Routing_Number" name="Routing_Number"  required numeric>
			</div>
			<div class="col-xs-3">
				<label for="Account_Number">Account Number </label>
				<input type="text" class="form-control" id="Account_Number" name="Account_Number"  required numeric>
			</div>
			<div class="col-xs-4">
				<label for="Type_of_Account">Type of Account </label>
				<select id="Type_of_Account" name="Type_of_Account" class="form-control" required>
					<option value="">Please Select...</option>
					<option value="Checking">Checking</option>
					<option value="Savings">Savings</option>
				</select>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<label for="Name_of_Auth">Name of your Authorizing Authority</label>
				<input type="text" class="form-control" id="Name_of_Auth" name="Name_of_Auth" required="required" />
			</div>
		</div>
	</div>

	<div class="form-footer">
		<div class="bottom-verbiage">
			<div class="row">
				<div class="col-xs-12">
					<div class="form-legal-text" style="text-align:justify;">
						I hereby authorize City of Bloomington Utilities, hereinafter called the COMPANY, to initiate ACH debits to the account identified in this form and authorize the institution to charge such debits to my account. <br /><br />Such debits shall be equal to monthly utility bill and payable monthly on the due date. Adjusting entries to correct errors are so authorized. It is agreed that these debits and adjustments will be made electronically and under the rules of the National Automated Clearing House Association (NACHA). This authorization is to remain in full force and effect until written notification is given to the COMPANY of its termination in such time and in such manner as to afford COMPANY and DEPOSITORY a reasonable opportunity to act on it. <br /><br /><b>Final bills will NOT be automatically withdrawn from your bank account.</b>
					</div>
				</div>
			</div>
			<div class="row">
				<div class="col-xs-12">
					<div class="form-legal-text">I affirm that the information contained herein, including attachment(s), is complete and accurate.</div>
				</div>
			</div>
			<div class="row" style="height:80px;">
				<div class="col-xs-6">
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
