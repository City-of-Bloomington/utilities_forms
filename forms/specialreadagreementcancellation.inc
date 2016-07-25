<script type="text/javascript">
	$(document).ready(function() {

	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="339">
	<input type="hidden" name="DocumentType" value="specialreadagreementcancellation">

	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Special Read Agreement Cancellation</h2></div>
		<div class="description">
			Are you a property owner who would like utilities to revert to your name when tenants move out? Sign up for a special read agreement, and we'll keep it on file so you will never have to worry about service disconnection in between tenants.
		</div>
		<?php
            include __DIR__.'/partials/contact-info.inc';
            include __DIR__.'/partials/required-fields.inc';
        ?>
	</div>

	<div class="form-body">
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					Please cancel the special read agreement on the following property/properties:
				</div>
			</div>
		</div>
		<table border=0>
			<tr>
				<td>
					<div class="row service_row service_row_first">
						<?= Application\Models\AddressService::renderFormFields(1,true,true); ?>
					</div>
				</td>
			</tr>
			<tr>
				<td>					
					<div class="row service_row service_row_hidden">
						<?= Application\Models\AddressService::renderFormFields(2,true,true); ?>
					</div>
				</td>
			</tr>
			<tr>
				<td>					
					<div class="row service_row service_row_hidden">
						<?= Application\Models\AddressService::renderFormFields(3,true,true); ?>
					</div>
				</td>
			</tr>
			<tr>
				<td>					
					<div class="row service_row service_row_hidden">
						<?= Application\Models\AddressService::renderFormFields(4,true,true); ?>
					</div>
				</td>
			</tr>
			<tr>
				<td>
					<div class="row service_row service_row_hidden">
						<?= Application\Models\AddressService::renderFormFields(5,true,true); ?>
					</div>
				</td>
			</tr>
		</table>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					The owner is
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="Owner_First_Name">First Name</label>
				<input type="text" class="form-control" name="OBKey__390_1" id="Owner_First_Name" required>
			</div>
			<div class="col-xs-6">
				<label for="Owner_Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__388_1" id="Owner_Last_Name" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					Name on special read agreement (if different from owner)
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-5">
				<label for="SRA_First_Name">First Name</label>
				<input type="text" class="form-control" id="SRA_First_Name" name="OBKey__391_1">
			</div>
			<div class="col-xs-6">
				<label for="SRA_Last_Name">Last Name</label>
				<input type="text" class="form-control" id="SRA_Last_Name" name="OBKey__389_1">
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
				<label for="Reason_for_Canc">Reason for Cancellation</label>
				<input type="text" class="form-control" id="Reason_for_Canc" name="OBKey__143_1" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-3">
				<label for="Auth_First_Name">Authorizer First Name</label>
				<input type="text" class="form-control" id="Auth_First_Name" name="Auth_First_Name" required>
			</div>
			<div class="col-xs-4">
				<label for="Auth_Last_Name">Authorizer Last Name</label>
				<input type="text" class="form-control" id="Auth_Last_Name" name="Auth_Last_Name" required>
			</div>
			<div class="col-xs-4">
				<label for="Authorizer_Title">Authorizer Title</label>
				<input type="text" class="form-control" id="Authorizer_Title" name="Authorizer_Title" required>
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
		<?php include APPLICATION_HOME.'/forms/partials/submit-fields.inc'; ?>
	</div>
</form>