"use strict";
/**
 * Opens a new window for the user to lookup an address
 *
 * When the user finally selects an address, the popup window is supposed
 * to call the callback function, ADDRESS_CHOOSER.setAddress().
 */
var ADDRESS_CHOOSER = {
    currentIndex: 0,
    popup: {},
    setAddress: function (number, direction, streetName) {
        // Update the form with the address information we got back
		$("input[name='OBKey__225_" + ADDRESS_CHOOSER.currentIndex + "']").val(number);
		$("input[name='OBKey__226_" + ADDRESS_CHOOSER.currentIndex + "']").val(direction);
		$("input[name='OBKey__104_" + ADDRESS_CHOOSER.currentIndex + "']").val(streetName);
		$('.modal').modal('toggle');
    },
    launchPopup: function (index) {
        ADDRESS_CHOOSER.currentIndex = index;
        ADDRESS_CHOOSER.popup = window.open(
            BASE_URL + '/address.php',
            'popup',
            'menubar=no,location=no,status=no,toolbar=no,width=800,height=600,resizeable=yes,scrollbars=yes'
        );
        ADDRESS_CHOOSER.popup.focus();
        return false;
    },
	showModal: function (index) {
		ADDRESS_CHOOSER.currentIndex = index;
		if($(".modal").length) {
			var modal = $(".modal");
		}
		else {
			var html = '<div class="modal fade" id="addressValidation" tabindex="-1" role="dialog" aria-labelledby="addressValidation">';
					html += '<div class="modal-dialog" role="document">';
						html += '<div class="modal-content">';
							html += '<div class="modal-header">';
								html += '<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>';
								html += '<h4 class="modal-title" id="myModalLabel">Address Lookup</h4>';
							html += '</div>';
							html += '<div class="modal-body">';
								html += "<h5>For best results, please include the street type in your search <br />(i.e. RD, ST, AVE, etc) and spell your street name correctly. <br /><br />Please also select the record that contains the appropriate unit, apartment, suite, etc. if applicable.</h5><hr>";
								html += "<div style=\"margin:5px;\"></div>";
							html += '</div>';
						html += '</div>';
					html += '</div>';
				html += '</div>';
			var modal = $(html);
			$('body').append(modal);
		}
		
		$.get('address.php',function(content) {
			modal.children().find('.modal-body').children("div").html(content);
			$("#addressValidation").modal('show');
		})

		return false;
	}
	
};
