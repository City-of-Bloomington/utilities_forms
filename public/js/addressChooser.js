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
        document.getElementById('OBKey__225_' + ADDRESS_CHOOSER.currentIndex).value = number;
        document.getElementById('OBKey__226_' + ADDRESS_CHOOSER.currentIndex).value = direction;
        document.getElementById('OBKey__104_' + ADDRESS_CHOOSER.currentIndex).value = streetName;

        ADDRESS_CHOOSER.popup.close();
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
    }
};
