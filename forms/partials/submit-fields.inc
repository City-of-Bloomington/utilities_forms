<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
?>
<div class="row">
    <div class="col-xs-6">
        <center>
        <?php Application\Models\Captcha::render(); ?>
        </center>
    </div>
</div>
<div class="row">
    <div class="col-xs-2"></div>
    <div class="col-xs-7">
        <center>
            <button type="submit" name="OBBtn_Save" value="Submit" class="btn btn-primary" id="form-submit" disabled="true">
                <i class="fa fa-check"></i>
                Submit
            </button>
        </center>
    </div>
    <div class="col-xs-2"></div>
</div>
