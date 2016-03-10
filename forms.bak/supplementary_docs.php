<script type="text/javascript">
	$(document).ready(function() {
		Global.Add_Supporting_Document_Upload();
		
	})
</script>
<form method="post" action="processor/forms.processor.php" id="form" name="form" enctype="multipart/form-data">
	<input type="hidden" name="DocumentTypeNum" name="DocumentTypeNum" value="340">
	<input type="hidden" name="DocumentType" name="DocumentType" value="SupplementaryDocument">
	<div class="form-header">
		<div class="form-title">City of Bloomington</div>
		<div class="form-title">Supplemental Document Upload</div>
	</div>

	<div class="form-body" style="margin:10px;">
		<div class="row">
			<div class="col-xs-12">
				File sizes must be less than 6 MB and we are only able to accept PDF or image files
			</div>
		</div>
	
		<div class="row">
			<div class="col-xs-12">
				<label for="Conf_Number">Confirmation Number</label>
				<input name="Conf_Number" type="text" class="form-control" value="<?php echo ($_GET['conf_num'] != "" ? $_GET['conf_num'] : "") ?>">
			</div>
		</div>
		<div class="row">
			
		</div>

	
	</div>

	<div class="form-footer">
		<div class="row">
			<div class="col-xs-12">
				<div class="form-legal-text">I affirm that the information contained herein, including attachment(s), is complete and accurate.</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-6">
				<div class="form-legal-input">
				
					<div class="checkbox" style="display:none;">
						<label>
							<input id="Agree" name="Agree" type="checkbox" value="Yes"> I Agree
						</label>
					</div>
					
					<div class="form-agree choose">
						<i class=""></i>
						<span>
							Click if you Agree
						</span>
					</div>
				</div>
			</div>
		</div>
		<div class="row">
			<div class="col-xs-2"></div>
			<div class="col-xs-8">
				<button class="btn btn-primary" id="form-submit" disabled><i class="fa fa-check"></i> Upload</button>
			</div>
			<div class="col-xs-2"></div>
		</div>
	</div>
</form>