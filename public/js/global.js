
var Global = function() {
	var SELF = this;
	var url = "processor/forms.processor.php";
	var SD = 1;
	var SA = 1;

	//ADD OR REMOVE SUPPLEMENTARY DOCUMENT TYPES HERE
	var Sup_Doc_Types = new Array(
		"Drivers License",
		"State ID",
		"School ID",
		"Military ID",
		"Passport",
		"Lease",
		"Power of Attorney",
		"Marriage License",
		"Divorce Decree",
		"Death Certificate",
		"Other"
	)

	this.init = function() {
		SELF.bindEvents();
		SELF.startup();
	}

	this.bindEvents = function() {
		$(document).off("change","#Person").on("change","#Person",function() {
			if($(this).val() == "Other") {
				$("#Other_Explain").parent().removeClass("hidden");
			}
			else {
				$("#Other_Explain").parent().addClass("hidden");
			}
			if($(this).val() == "Owner") {
				if($("#First_Name").val() != "" && $("#Last_Name").val() != "") {
					$("#Property_Owner").val($("#First_Name").val() + " " + $("#Last_Name").val());
				}
				$("#Owner_Phone_Number").val($("#Telephone_Number").val());
			}
		})
		$(document).off("change","#CommercialPerson").on("change","#CommercialPerson",function() {
			if($(this).val() == "Other") {
				$("#Other_Explain").parent().removeClass("hidden");
			}
			else {
				$("#Other_Explain").parent().addClass("hidden");
			}
			if($(this).val() == "Owner") {
				if($("#Contact_First_Name").val() != "" && $("#Contact_Last_Name").val() != "") {
					$("#Property_Owner").val($("#Contact_First_Name").val() + " " + $("#Contact_Last_Name").val());
				}
				if($("#Contact_Phone_Num").val() != "") {
					$("#Owner_Phone_Number").val($("#Contact_Phone_Num").val());
				}
			}
		})
		$(document).off("change","#IndividualPerson").on("change","#IndividualPerson",function() {
			if($(this).val() == "Other") {
				$("#Other_Explain").parent().removeClass("hidden");
			}
			else {
				$("#Other_Explain").parent().addClass("hidden");
			}
			if($(this).val() == "Owner") {
				if($("#First_Name").val() != "" && $("#Last_Name").val() != "") {
					$("#Property_Owner").val($("#First_Name").val() + " " + $("#Middle_Name").val() + " " + $("#Last_Name").val());
				}
				if($("#Telephone_Number").val() != "") {
					$("#Owner_Phone_Number").val($("#Telephone_Number").val());
				}
			}
		})
		$(document).off("change","#New_Customer").on("change","#New_Customer",function() {
			SELF.Check_All_Valid();
			if($(this).val() == "No") {
				$("#Customer_Acct_Num").parent().removeClass("hidden");
				//$("#Customer_Acct_Num").attr("required",true);
				//$("#Customer_Acct_Num").prev('label').append(" <req>*</req>");
			}
			else {
				$("#Customer_Acct_Num").parent().addClass("hidden");
				//$("#Customer_Acct_Num").removeAttr("required");
				//$("#Customer_Acct_Num").prev().children().remove("req");
			}
		})
		$(document).off("click","#Agree").on("click","#Agree",function(e) {
			SELF.Check_All_Valid(e);
			//SELF.Agree_Check();
		})

		$(document).off("click","#form-submit").on("click","#form-submit",function() {
			SELF.Submit_Form();
		})

		$(document).off("mouseenter",".form-agree").on("mouseenter",".form-agree",function() {
			$(document).off("click",".form-agree").on("click",".form-agree",function() {
				SELF.Agree_Toggle();
			})
			$(document).off("mouseleave",".form-agree").on("mouseleave",".form-agree",function() {
				$(document).off("click",".form-agree");
			})
		})

		$(document).off("keydown","input").on("keydown","input",function(e) {
			var keys = new Array(65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90);
			var nums = new Array(48,49,50,51,52,53,54,55,56,57,96,97,98,99,100,101,102,103,104,105);
			var ctrl = new Array(8,9,13,17,18,32,37,38,39,40,45,46);
			var spec = new Array(48,49,50,51,52,53,54,55,56,57,96,97,98,99,100,101,102,103,104,105,8,9,13,17,18,32,37,38,39,40,45,46,109,173,189);


			if($.inArray(e.which,ctrl) !== -1 || (e.which == 9 && e.shiftKey) || ($.inArray(e.which,nums) && e.shiftKey && $(e.target).attr("numeric") === undefined)) {
				return true;
			}
			if($.inArray(e.which,keys) !== -1 && $(e.target).attr("alpha") !== undefined) {
				e.preventDefault();
				SELF.toUpper(e);
				return false;
			}
			if($.inArray(e.which,keys) !== -1 && $(e.target).attr("spec") === undefined && $(e.target).attr("ssn") === undefined && $(e.target).attr("numeric") === undefined && $(e.target).attr("phone") === undefined) {
				e.preventDefault();
				SELF.toUpper(e);
				return false;
			}
			if($(e.target).attr("spec") !== undefined && $.inArray(e.which,spec) === -1) {
				e.preventDefault();
				return false;
			}
			if($(e.target).attr("phone") !== undefined && $.inArray(e.which,nums) === -1) {
				e.preventDefault();
				return false;
			}
			if(($(e.target).attr("numeric") !== undefined && $.inArray(e.which,nums) === -1) || e.shiftKey) {
				e.preventDefault();
				return false;
			}
		})

		$(document).off("click","#dev").on("click","#dev",function() {
			SELF.Populate_for_Dev();
		})

		$(document).off("click","#Add_More").on("click","#Add_More",function(e) {
			e.preventDefault();
			SELF.Add_Supporting_Document_Upload();
			return false;
		})

		$(document).off("blur","input, select").on("blur","input, select",function(e) {
			//SELF.Check_Single_Valid(e);
			SELF.Check_All_Valid(e);
		})

		$(document).off("keyup","input, select").on("keyup","input, select",function(e) {
			//SELF.Check_Single_Valid(e);
			SELF.Check_All_Valid(e);
		})

		$(document).off("change","input, select").on("change","input, select",function(e) {
			//SELF.Check_Single_Valid(e);
			SELF.Check_All_Valid(e);
		})

		$(document).off("focusout","input, select").on("focusout","input, select",function(e) {
			//SELF.Check_Single_Valid(e);
			SELF.Check_All_Valid(e);
		})

		$(document).off("click","#Auto_Fill_Mailing_Address").on("click","#Auto_Fill_Mailing_Address",function(e) {
            e.preventDefault();
            $("#Mailing_Address").val($("#Service_St_Num").val() + " " + $("#Service_St_Dir").val() + " " + $("#Service_St_Name").val());
			$("#Mailing_City").val(($("#City").val().length ? $("#City").val() : "Bloomington");
			$("#Mailing_State").val(($("#State").val().length ? $("#State").val() : "IN");
			$("#Mailing_Zipcode").val(($("#ZIP").val().length ? $("#ZIP").val() : "47401");
			return false;
		})

		$(document).off("click","#Add_More_Addresses").on("click","#Add_More_Addresses",function(e) {
			e.preventDefault;
			SELF.Add_New_Service_Row();
			return false;
		})

	}

	this.Make_Invalid = function(item) {
		item.css("border-color","red");
		item.css("border-width","2px");
		item.css("background-color","#FCD1D1");
	}

	this.Make_Valid = function(item) {
		item.css("border-color","");
		item.css("border-width","");
		item.css("background-color","");
	}

	this.Check_All_Valid = function(e) {
		if(e !== undefined) {
			$(e.target).attr("validate",true);
		}
		var valid = $("#Agree").is(":checked");
		$("input:visible, select:visible").each(function() {
			var item = $(this);
			//CHECK REQUIRED FIELDS ARE NOT BLANK
			if(item.attr("required") !== undefined && (item.val() == "" || item.val().replace(/_/g,"9") == item.attr("mask")) && !item.is(":focus")) {
				valid = false;
				if(item.attr("validate") !== undefined) {
					SELF.Make_Invalid(item);
				}
			}
			else if(item.val() != "" && item.attr("numeric") !== undefined && item.attr("ssn") === undefined && item.attr("phone") === undefined && !SELF.Check_Type_Valid(item)) {
				valid = false;
				if(item.attr("validate") !== undefined) {
					SELF.Make_Invalid(item);
				}
			}
			else if(item.attr("ssn") !== undefined || item.attr("phone") !== undefined) {
				SELF.Make_Valid(item);
			}
			else {
				SELF.Make_Valid(item);
			}
		})

		if(valid == true) {
			$("#form-submit").removeAttr("disabled").removeProp("disabled");
		}
		else {
			$("#form-submit").attr("disabled",true).prop("disabled",true);
		}
	}

	this.Check_Special_Characters = function(item) {
		if(item.attr("phone") !== undefined || item.attr("ssn") !== undefined) {
			return false;
		}
	}

	this.Check_Type_Valid = function(item) {
		var valid = false
		if(item.attr("numeric") !== undefined) {
			valid = $.isNumeric(item.val());
		}
		return valid;
	}

	this.Check_Single_Valid = function(e) {
		var item = $(e.target);
		//CHECK REQUIRED FIELDS ARE NOT BLANK
		if(item.attr("required") !== undefined && item.val() == "" && !item.is(":focus")) {
			item.css("border-color","red");
			item.css("border-width","2px");
			item.css("background-color","#FCD1D1");
		}
		//CHECK INPUT TYPES ARE CORRECT
		else if(item.val() != "" && SELF.Check_Type_Valid(item) == false) {
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

	this.Populate_for_Dev = function() {
		$("input[id='First_Name']").val("Albert");
		$("input[id='Middle_Name']").val("Randy");
		$("input[id='Last_Name']").val("Welch");
		$("input[id='Service_Address']").val("6 Talisman Hill");
		$("input[id='Service_St_Num']").val("6");
		$("input[id='Service_St_Dir']").val("N");
		$("input[id='Service_St_Name']").val("Talisman Hill");
		$("input[id='Mailing_Address']").val("6 Talisman Hill");
		$("input[id='Date_of_Birth']").val("12/01/1970");
		$("input[id='Soc_Sec_Num']").val("123-12-1234");
		$("input[id='Drivers_Lic_Num']").val("1231-12-1234");
		$("input[id='Telephone_Number']").val("(812) 123-1234");
		$("input[id='Email_Address']").val("abc@abc.def");
		$("select[id='Person']").val("Tenant");

		$("select[id='CommercialPerson']").val("Tenant");
		$("input[id='Property_Owner']").val("Bob Fred");
		$("input[id='Owner_Phone_Number']").val("(555) 555-5555");
		$("input[id='Employers_Name']").val("Bob George");
		$("input[id='Employers_Ph_Num']").val("(555) 555-5555");
		$("input[id='Date_of_Change']").val("01/01/2015");
		$("input[id='Customer_Acct_Num']").val("132454554");
		$("select[id='New_Customer']").val("Yes");
		$("input[id='Emergency_Name']").val("Bob Fred");
		$("input[id='Emergency_Phone']").val("(555) 555-5555");
		$("input[id='Soc_Sec_Num']").val("333-33-3333");
		$("input[id='Customer_Fed_TIN']").val("123456789");
		$("input[id='Date_of_Inc']").val("01/01/1970");
		$("input[id='Name_of_Fin_Inst']").val("Bank of Trust");
		$("input[id='Routing_Number']").val("12345678");
		$("input[id='Account_Number']").val("123456789");
		$("select[id='Type_of_Account']").val("Checking");
		$("input[id='Name_of_Auth']").val("Bob Fred");
		$("input[id='Owner_First_Name']").val("Bob");
		$("input[id='Bus_St_Num']").val("6");
		$("input[id='Bus_St_Dir']").val("N");
		$("input[id='Bus_St_Name']").val("Talisman Hill");
		$("input[id='Owner_First_Name']").val("Bob");
		$("input[id='Owner_Last_Name']").val("Fred");
		$("input[id='Owner_Title']").val("Bob Fred");
		$("input[id='Corporate_Name']").val("Business 123");
		$("input[id='Company_Name']").val("Business 123");
		$("input[id='Company_CKA']").val("Business Numbers");
		$("input[id='Mailing_First_Name']").val("Bob");
		$("input[id='Mailing_Last_Name']").val("Fred");
		$("input[id='Mailing_Street_Number']").val("6");
		$("input[id='Mailing_Street_Direction']").val("N");
		$("input[id='Mailing_Street_Name']").val("Talisman Hill");
		$("input[id='State_of_Inc']").val("IN");
		$("input[id='Federal_ID']").val("123456789");
		$("input[id='Bus_Phone_Number']").val("(555) 555-5555");
		$("input[id='Contact_First_Name']").val("Bob");
		$("input[id='Contact_Last_Name']").val("Fred");
		$("input[id='Contact_Phone_Num']").val("(555) 555-5555");
		$("input[id='Other_Explain']").val("Other Explanation");
		$("input[id='Title']").val("Owner");
		$("input[id='Date_of_Disconnect']").val("01/01/1970");
		$("input[id='Mailing_Address']").val("6 N Talisman Hill");
		$("input[id='Service_Apartment']").val("45");
		$("input[id='Mailing_City']").val("Bloomington");
		$("input[id='Mailing_State']").val("IN");
		$("input[id='ZIP_Code']").val("12345");
		$("input[id='Mailing_Zipcode']").val("12345");
		$("input[id='Service_Zipcode']").val("12345");
		$("input[id='Forwarding_Tel_Num']").val("(555) 555-5555");
		$("input[id='Reason_for_Canc']").val("Moving");
		$("input[id='Auth_First_Name']").val("Bob");
		$("input[id='Auth_Last_Name']").val("Fred");
		$("input[id='Authorizer_Title']").val("Owner");
		$("input[id='SRA_First_Name']").val("Bob");
		$("input[id='SRA_Last_Name']").val("Fred");
		$("input[id='Effective_Date']").val("01/01/2015");
		$("input[id='Management_Company']").val("Bob Jones, Inc");
		$("input[id='Former_Last_Name']").val("Sampson");
	}

	this.toUpper = function(e) {
		if(e !== undefined) {
			var val = String.fromCharCode(e.keyCode).toUpperCase();
			$(e.target).val($(e.target).val() + val)
		}
	}

	this.Agree_Check = function() {
		var item = $("#Agree")
		if(item.is(":checked") == true && SELF.Check_All_Valid()) {
			$("#form-submit").removeAttr("disabled").removeProp("disabled");
		}
		else {
			$("#form-submit").attr("disabled",true).prop("disabled",true);
		}
	}

	this.Submit_Form = function() {
		var vals = {};
		$("input[type='text'], select").each(function() {
			vals[$(this).attr("id")] = $(this).val();
		})
		$("input[type='checkbox']").each(function() {
			vals[$(this).attr("id")] = $(this).is(":checked");
		})
		$.post(url,{
			c:"",
			vals:vals
		},function(result) {
		})
	}

	this.Setup_Masks = function() {
		$("input, select").each(function() {
			if($(this).attr("mask") !== undefined) {
				$(this).mask($(this).attr("mask"));
			}
		})
	}

	this.startup = function() {
		$('input,textarea').attr('autocomplete', 'off');
		$(document).ready(function() {
			SELF.Setup_Masks();
			SELF.Check_All_Valid();
			if($("#Agree").is(':checked')) {
				SELF.Check_All_Valid();
			}
			$("input, select").each(function() {
				if($(this).attr("required") !== undefined) {
					$(this).prev('label').append(" <req>*</req>");
				}
			})
		})
	}

	this.Set_Agree_Box = function(checked) {
		if(checked == true) {
			$('#Agree').attr("checked", true).prop("checked",true);
			$(".form-agree").removeClass("choose").addClass("agree");
			$(".form-agree").children("i").attr("class","fa fa-check");
			$(".form-agree").children("span").html("I Agree");
		}
		if(checked == false) {
			$('#Agree').attr("checked", false).prop("checked",false);
			$(".form-agree").removeClass("agree").addClass("choose");
			$(".form-agree").children("i").attr("class","");
			$(".form-agree").children("span").html("Click if you Agree");
		}
	}

	this.Agree_Toggle = function() {
		$("#form-submit").attr("disabled",true);
		if($("#Agree").is(":checked")) {
			SELF.Set_Agree_Box(false);
		}
		else {
			SELF.Set_Agree_Box(true);
			SELF.Check_All_Valid();
		}
	}

	this.Add_New_Service_Row = function() {
		$("#Add_More_Addresses").remove();
		if(SA < 6) {
			SA = SA + 1;
			var newRow = $(".service_row:visible:last").next();
			newRow.removeClass("service_row_hidden");
			newRow.children().find("#Service_St_Num").attr("required", true).prev("label").append("<req>*</req>");
			newRow.children().find("#Service_St_Name").attr("required", true).prev("label").append("<req>*</req>");
			//SET NEXT SERVICE ST DIR TO N/A
			//newRow.children().find("#Service_St_Dir")[0];

		}
	}

	this.Add_Supporting_Document_Upload = function() {

		$("#Add_More").remove();
		if(SD < 4) {
			var html = "<div class=\"row\" style=\"border-bottom:1px solid lightgray; padding-top:15px; padding-bottom:15px;\">";
					html += "<div class=\"col-xs-4\">";
						html += "<select name=\"Sup_Type_" + SD + "\" class=\"form-control\">";
							html += "<option value=\"\">Please Select...</option>";
							$.each(Sup_Doc_Types,function(key,val) {
								html += "<option value=\"" + val + "\">" + val + "</option>";
							})
						html += "</select>";
					html += "</div>";
					html += "<div class=\"col-xs-5\">";
						html += "<input type=\"file\" class=\"Sup_File btn btn-primary\" name=\"Sup_File_" + SD + "\">";
					html += "</div>";
					if(SD < 3) {
						html += "<div class=\"col-xs-2\">";
							html += "<button style=\"margin-left:15px;\" id=\"Add_More\" type=\"button\" class=\"btn btn-success\"><i class=\"fa fa-plus\"></i> Add</i></button>";
						html += "</div>";
					}

				html += "</div>";
			$(".form-body").append(html);
			SD = SD + 1;
		}
	}

}