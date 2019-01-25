"use strict";
var ADDRESS_CHOOSER = {
    currentIndex:       0,
    chosenAddressIndex: 0,

    /**
     * Initiate a new modal instance for the chooser
     *
     * Several of the forms allow for multiple address.  All of the input names
     * for an address will be appended with the index number.
     *
     * @param int    index
     * @param string previousSearch Previous search string
     */
    start: function (index, previousSearch) {
        let modal = document.getElementById('addressValidation');

        if (!modal) { modal = ADDRESS_CHOOSER.createModal(); }
        ADDRESS_CHOOSER.currentIndex = index;

        window.startChooser(
            document.getElementById('chooser'),
            function (chosenAddress) {
                // Update the form with the address information we got back
                $("input[name='OBKey__225_" + ADDRESS_CHOOSER.currentIndex + "']").val(ADDRESS_CHOOSER.streetNumber(chosenAddress));
                $("input[name='OBKey__226_" + ADDRESS_CHOOSER.currentIndex + "']").val(chosenAddress.street_direction);
                $("input[name='OBKey__104_" + ADDRESS_CHOOSER.currentIndex + "']").val(ADDRESS_CHOOSER.streetName(chosenAddress));
                ADDRESS_CHOOSER.destroyModal();
                Global.Check_All_Valid();
            },
            previousSearch
        );
    },

    /**
     * Returns a streetNumber string by parsing address data
     *
     * @param  object address
     * @return string
     */
    streetNumber: function (address) {
        let number = '';

        if (address.street_number_prefix) { number += address.street_number_prefix + ' '; }
        number += address.street_number;
        if (address.street_number_suffix) { number += ' ' + address.street_number_suffix; }

        return number;
    },

    /**
     * Returns the streetName string by parsing address data
     *
     * Since direction is a seperate input in the form, the string returned
     * will not include the street direction.
     *
     * @param  object address
     * @return string
     */
    streetName: function (address) {
        let name = address.street_name;

        if (address.street_suffix_code   ) { name += ' ' + address.street_suffix_code;    }
        if (address.street_post_direction) { name += ' ' + address.street_post_direction; }
        // Subunit might have been added to the address information,
        // if the user chose a subunit of the address
        if (address.subunit              ) { name += ' ' + address.subunit; }

        return name;
    },

    /**
     * Appends the modal div to the document body
     */
    createModal: function () {
        // Create the outer element using createElement, so we can
        // append the element to the document body.
        let div = document.createElement('DIV');
        div.setAttribute('id',              'addressValidation');
        div.setAttribute('aria-labelledby', 'addressValidation');
        div.setAttribute('role',            'dialog');
        div.setAttribute('class',           'modal fade');
        div.setAttribute('tabindex',        '1');

        div.innerHTML = '<div class="modal-dialog" role="document">'
                      + '   <div class="modal-content">'
                      + '       <div class="modal-header">'
                      + '           <button type="button" class="close" data-dismiss="modal" aria-label="Close" onclick="ADDRESS_CHOOSER.destroyModal();"><span aria-hidden="true">&times;</span></button>'
                      + '           <h4 class="modal-title" id="myModalLabel">Address Lookup</h4>'
                      + '       </div>'
                      + '       <div class="modal-body">'
                      + '           <p>For best results, please include the street type in your search (i.e. RD, ST, AVE, etc) and spell your street name correctly.</p>'
                      + '           <p>Please also select the record that contains the appropriate unit, apartment, suite, etc. if applicable.</p><hr />'
                      + '           <div id="chooser"></div>'
                      + '       </div>'
                      + '   </div>'
                      + '</div>';

        document.body.appendChild(div);
        $('#addressValidation').modal('show');
        return div;
    },

    /**
     * Removes the modal div from the DOM
     */
    destroyModal: function () {
        $('#addressValidation').modal('hide');
        document.body.removeChild(document.getElementById('addressValidation'));
    },
};

(function (window) {
    let resultsDiv, // HTMLElement to draw the choose into
        results,    // Variable to store search result data
        callback,   // Function to call once the user makes a choice

        /**
         * Writes the chooser into an HTML element.
         *
         * Calls the callback function with the chosen data once the user
         * chooses something.
         *
         * @param Element  target   The DOM element to draw the chooser into
         * @param function call     Function to call with the chosen data
         * @param string   existing Previous search string
         */
        startChooser = function (target, call, existing) {
            callback = call;
            target.innerHTML = '<form method="get" id="addressSearchForm">'
                             + '    <fieldset><legend>Find an address</legend>'
                             + '        <div class="form-inline">'
                             + '            <div class="form-group">'
                             + '                <input style="width:425px;" class="form-control" name="query" id="query" />'
                             + '                <button id="searchAddress" class="btn btn-primary" type="submit">'
                             + '                    <i class="fa fa-search"></i>'
                             + '                    Search'
                             + '                </button>'
                             + '            </div>'
                             + '        </div>'
                             + '    </fieldset>'
                             + '</form>'
                             + '<div id="searchResults" style="width:550px;height:260px;overflow:auto;"></div>';

            resultsDiv = document.getElementById('searchResults');
            document.getElementById('query').focus();
            document.getElementById('addressSearchForm').addEventListener('submit', function (e) {
                e.preventDefault();
                searchAddress(document.getElementById('query').value);
            }, false);

            if (existing) {
                document.getElementById('query').value = existing;
                searchAddress(existing);
            }
        },

        searchAddress = function (address) {
            let req = new XMLHttpRequest();

            req.addEventListener('load', resultsHandler);
            req.open('GET', ADDRESS_SERVICE + '/addresses?format=json;address=' + address);
            req.send();
        },

        /**
         * Draws the search results into the modal div
         */
        resultsHandler = function (event) {
            results = [];

            try { results = JSON.parse(event.target.responseText); }
            catch (e) { resultsDiv.innerHTML = e.message; }

            if (results.length) {
                resultsDiv.innerHTML = '';
                resultsDiv.appendChild(addressesToHTML(results));
            }
            else {
                resultsDiv.innerHTML = 'No results found';
            }
        },

        /**
         * Creates the HTML for the search results
         *
         * Returns an Element node to ready to be appended to the DOM.
         * Each result will have an eventListener already attached.
         *
         * Search results should come in as an array of objects.
         *
         * For each search result, we store the array index as a data
         * attribute.  Later on, you should be able to use that index
         * to pull the object data from the results variable.
         *
         * @param  array   Search result data
         * @return ELement
         */
        addressesToHTML = function (results) {
            let table = document.createElement('TABLE'),
                tr;

            results.forEach(function (row, i, array) {
                tr           = document.createElement('TR');
                tr.innerHTML = '<td data-index="' + i + '">' + row.streetAddress + ', ' + row.city + '</td>';
                tr.addEventListener('click', chooseAddress, false);
                table.appendChild(tr);
            });
            return table;
        },

        /**
         * Look up detailed address information
         *
         * @param object   address  An address search result
         * @param function f        Callback function to return the information to
         */
        addressInfo = function (address, f) {
            let req = new XMLHttpRequest();

            req.addEventListener('load', f);
            req.open('GET', ADDRESS_SERVICE + '/addresses/' + address.id + '?format=json');
            req.send();
        },

        /**
         * Handler for when a user chooses on of the results
         */
        chooseAddress = function (event) {
            resultsDiv.innerHTML = '';
            ADDRESS_CHOOSER.chosenAddressIndex = event.target.dataset.index;

            addressInfo(results[ADDRESS_CHOOSER.chosenAddressIndex], function (e) {
                let address;

                try {
                    address = JSON.parse(e.target.responseText);
                    if (address.subunits.length) {
                        resultsDiv.innerHTML = '';
                        resultsDiv.appendChild(subunitsToHTML(address.subunits));
                    }
                    else {
                        callback(address.address);
                    }

                }
                catch (e) {
                    callback(results[ADDRESS_CHOOSER.chosenAddressIndex]);
                }
            });
        },

        /**
         * Creates the HTML for choosing a subunit
         *
         * Returns an Element node to ready to be appended to the DOM.
         * Each subunit will have an eventListener already attached.
         *
         * Pass in the subunits array from an addressInfo request
         *
         * @param array subunits  An array of Subunit objects
         */
        subunitsToHTML = function (subunits) {
            let table = document.createElement('TABLE'),
                tr;
            table.innerHTML = '<caption>Choose a subunit</caption>';

            subunits.forEach(function (subunit, i, array) {
                tr           = document.createElement('TR');
                tr.innerHTML = '<td>' + subunit.type_code + ' ' + subunit.identifier + '</td>';
                tr.addEventListener('click', chooseSubunit, false);
                table.appendChild(tr);
            });
            return table;
        },

        /**
         * Handler for when a user chooses one of the subunits
         *
         * Appends the subunit name to the address info in the results variable.
         * Then, call the callback function, passing the result address
         */
        chooseSubunit = function (event) {
            resultsDiv.innerHTML = '';
            // Add the subunit information to the address
            results[ADDRESS_CHOOSER.chosenAddressIndex].subunit = event.target.innerHTML;

            callback(results[ADDRESS_CHOOSER.chosenAddressIndex]);
        };

    window.startChooser = startChooser;
})(window);
