
	
	var init = function() {
		bindEvents();
		startup();
	}
	
	var Add_Supporting_Document_Upload = function() {
		return true;
	}	
	
	var bindEvents = function() {
		$(document).off("change","#Person").on("change","#Person",function() {
			if($(this).val() == "Other") {
				$("#Other_Explain").parent().removeClass("hidden");
			}
			else {
				$("#Other_Explain").parent().addClass("hidden");
			}
		})
		
		$(document).off("keydown","input").on("keydown","input",function(e) {
			var keys = new Array(65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90);
			var nums = new Array(48,49,50,51,52,53,54,55,56,57,96,97,98,99,100,101,102,103,104,105);
			var ctrl = new Array(8,9,13,16,17,18,32,37,38,39,40,45,46);
			var addr = new Array(48,49,50,51,52,53,54,55,56,57,96,97,98,99,100,101,102,103,104,105,191);
			
			if($.inArray(e.which,ctrl) !== -1) {
				return true;
			}			
			if($.inArray(e.which,keys) !== -1 && $(e.target).attr("alpha") !== undefined) {
				e.preventDefault();
				toUpper(e);
				return false;
			}
			if($.inArray(e.which,keys) !== -1 && $(e.target).attr("numeric") === undefined && $(e.target).attr("phone") === undefined && $(e.target).attr("address") === undefined) {
				e.preventDefault();
				toUpper(e);
				return false;
			}
			if($(e.target).attr("phone") !== undefined && $.inArray(e.which,nums) === -1) {
				console.log("phone");
				e.preventDefault();
				return false;
			}						
			if($(e.target).attr("numeric") !== undefined && $.inArray(e.which,nums) === -1) {
				e.preventDefault();
				return false;
			}
			if(($(e.target).attr("address") !== undefined && $.inArray(e.which,addr) === -1) || e.shiftKey) {
				e.preventDefault();
				return false;
			}				
		})
		
		$(document).off("blur","input, select").on("blur","input, select",function(e) {
			//Check_Single_Valid(e);
			Check_All_Valid(e);
		})
		
		$(document).off("keyup","input, select").on("keyup","input, select",function(e) {
			//Check_Single_Valid(e);
			Check_All_Valid(e);
		})

		$(document).off("change","input, select").on("change","input, select",function(e) {
			//Check_Single_Valid(e);
			Check_All_Valid(e);
		})	

		$(document).off("focusout","input, select").on("focusout","input, select",function(e) {
			//Check_Single_Valid(e);
			Check_All_Valid(e);
		})		

	}
	
	var Make_Invalid = function(item) {
		item.css("border-color","red");
		item.css("border-width","2px");
		item.css("background-color","#FCD1D1");	
	}
	
	var Make_Valid = function(item) {
		item.css("border-color","");
		item.css("border-width","");
		item.css("background-color","");	
	}
	
	var Check_All_Valid = function(e) {
		if(e !== undefined) {
			$(e.target).attr("validate",true);
		}
		var valid = $("#Agree").is(":checked");
		$("input, select").each(function() {
			var item = $(this);
			//CHECK REQUIRED FIELDS ARE NOT BLANK
			if(item.attr("required") !== undefined && (item.val() == "" || item.val().replace(/_/g,"9") == item.attr("mask")) && !item.is(":focus")) {
				valid = false;
				if(item.attr("validate") !== undefined) {
					Make_Invalid(item);
				}
			}
			else if(item.val() != "" && item.attr("numeric") !== undefined && item.attr("ssn") === undefined && item.attr("phone") === undefined && !Check_Type_Valid(item)) {
				valid = false;
				if(item.attr("validate") !== undefined) {
					Make_Invalid(item);
				}
			}
			else if(item.attr("ssn") !== undefined || item.attr("phone") !== undefined) {
				Make_Valid(item);
			}
			else {
				Make_Valid(item);
			}
		})

		if(valid == true) {
			$("#form-submit").removeAttr("disabled").removeProp("disabled");
		}
		else {
			$("#form-submit").attr("disabled",true).prop("disabled",true);
		}
	}
	
	var Check_Special_Characters = function(item) {
		if(item.attr("phone") !== undefined || item.attr("ssn") !== undefined) {
			return false;
		}
	}
	
	var Check_Type_Valid = function(item) {
		var valid = false
		if(item.attr("numeric") !== undefined) {
			valid = $.isNumeric(item.val());
		}
		return valid;
	}
	
	var Check_Single_Valid = function(e) {
		var item = $(e.target);
		//CHECK REQUIRED FIELDS ARE NOT BLANK
		if(item.attr("required") !== undefined && item.val() == "" && !item.is(":focus")) {
			item.css("border-color","red");
			item.css("border-width","2px");
			item.css("background-color","#FCD1D1");
		}
		//CHECK INPUT TYPES ARE CORRECT
		else if(item.val() != "" && Check_Type_Valid(item) == false) {
			item.css("border-color","red");
			item.css("border-width","2px");
			item.css("background-color","#FCD1D1");
		}
		else {
			item.css("border-color","");
			item.css("border-width","");
			item.css("background-color","");
		}
	}

	
	var toUpper = function(e) {
		if(e !== undefined) {
			var val = String.fromCharCode(e.keyCode).toUpperCase();
			$(e.target).val($(e.target).val() + val)
		}
	}

	
	var Setup_Masks = function() {
		$("input, select").each(function() {
			if($(this).attr("mask") !== undefined) {
				$(this).mask($(this).attr("mask"));
			}
		})
	}
	
	var startup = function() {
		$('input,textarea').attr('autocomplete', 'off');
		$(document).ready(function() {
			Setup_Masks();
			Check_All_Valid();
			if($("#Agree").is(':checked')) {
				Check_All_Valid();
			}
			$("#form-submit").html("Save");
			$("input, select").each(function() {
				if($(this).attr("required") !== undefined) {
					$(this).prev('label').append(" <req>*</req>");
				}
			})
			$("button[name='OBBtn_Save']").removeAttr("disabled");
			//$(".hidden").css("display","block");
			$("#Customer_Acct_Num").parent().css("display","block");
			$(".hidden").removeClass("hidden");
			//setTimeout(function() {
				//alert("Save button exists: " + $("button[name='OBBtn_Save']").length);
				//alert("Save button is disabled: " + $("button[name='OBBtn_Save']").attr("disabled"));
			//},2500)
		})
	}