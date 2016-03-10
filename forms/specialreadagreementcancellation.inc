<script type="text/javascript">
	$(document).ready(function() {

	})
</script>
<form method="post" action="<?= BASE_URI; ?>/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" value="339">
	<input type="hidden" name="DocumentType" value="specialreadagreementcancellation">

	<div class="form-header">
		<div class="form-title logo"><img src="assets/images/logo.png"> City of Bloomington Utilities <img src="assets/images/logo.png"></div>
		<div class="form-title"><h2>Special Read Agreement Cancellation</h2></div>
		<div class="description">
			Are you a property owner who would like utilities to revert to your name when tenants move out? Sign up for a special read agreement, and we'll keep it on file so you will never have to worry about service disconnection in between tenants.
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
			<div class="col-xs-11">
				<div class="form-legal-text">
					Please cancel the special read agreement on the following property/properties:
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
				<!--<input type="text" class="form-control" name="OBKey__226_1" id="Service_St_Dir">-->
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