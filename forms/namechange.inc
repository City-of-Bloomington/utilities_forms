<script type="text/javascript">
	$(document).ready(function() {
		var req = $("<req style=\"float:left;\">*</req>")
		setTimeout(function() {
			$("input[name='Sup_File_1']")
				.attr("required",true)
				.parents(".row")
				.prepend(req);
		},500)
	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="338">
	<input type="hidden" name="DocumentType" value="namechange">
	<div class="form-header">

	<div class="form-header">
        <?php include __DIR__.'/partials/form-title-logo.inc'; ?>
		<div class="form-title"><h2>Request for Individual Name Change</h2></div>
		<div class="description">
			<b>Name change</b> request form. You will need a substantiating document (marriage license, divorce decree, etc.) to attach as a file to this form.
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
				<input type="text" class="form-control" name="OBKey__137_1" id="First_Name" required>
			</div>
			<div class="col-xs-4">
				<label for="Middle_Name">Middle Name</label>
				<input type="text" class="form-control" name="OBKey__156_1" id="Middle_Name">
			</div>
			<div class="col-xs-3">
				<label for="Last_Name">Last Name</label>
				<input type="text" class="form-control" name="OBKey__121_1" id="Last_Name" required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<label for="Former_Last_Name">Former Last Name</label>
				<input type="text" class="form-control" name="OBKey__387_1" id="Former_Last_Name" required>
			</div>
			<div class="col-xs-5">
				<label for="Telephone_Number">Telephone Number</label>
				<input type="text" class="form-control" name="Telephone_Number" id="Telephone_Number" mask="(999) 999-9999" phone required>
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
			<div class="col-xs-6">
				<label for="Customer_Acct_Num">City of Bloomington Utilities Account Number</label>
				<input type="text" class="form-control" name="OBKey__125_1" id="Customer_Acct_Num" spec required>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-11">
				<div class="form-legal-text">
					Please include either a photcopy of your driver's license, a marriage license, or a divorce decree. If you send a driver's license, please make sure it shows the new name change.
				</div>
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