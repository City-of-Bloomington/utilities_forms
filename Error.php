<?php
/**
 * Class for custom error handling
 *
 * Applications need to do more with errors than just display or log the error.
 * Error handling should be configurable in the configuration.inc
 * The $ERROR_REPORTING variable declared in configuration.inc controls the
 * various possibile things to do with errors.
 *
 * @copyright 2013-2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Blossom\Classes;

class Error
{
    /**
     * Checks for a fatal error and calls our custom error handler
     */
    public static function shutdownHandler()
    {
        $e = error_get_last();
        if ($e['type'] == E_ERROR) {
            self::customExceptionHandler(new \ErrorException($e['message'], 0, $e['type'], $e['file'], $e['line']));
        }
    }

	/**
	* Provide nicely formatted error messages when PHP bombs out.
	*/
	public static function customErrorHandler($errno, $errstr, $errfile, $errline)
	{
        self::customExceptionHandler(new \ErrorException($errstr, 0, $errno, $errfile, $errline));
	}

	/**
	 * Object oriented exceptions are handled differently from other PHP errors.
	 */
	public static function customExceptionHandler($exception)
	{
		global $ERROR_REPORTING;

		if (isset($ERROR_REPORTING)) {
            $script  = isset($_SERVER['REQUEST_URI']) ? $_SERVER['REQUEST_URI'] : $_SERVER['SCRIPT_NAME'];
            $server  = isset($_SERVER['SERVER_NAME']) ? $_SERVER['SERVER_NAME'] : 'localhost';

            $subject = APPLICATION_NAME.' Error';
            $message = "\t$script\n\nError on line {$exception->getLine()} of file {$exception->getFile()}:\n{$exception->getMessage()}\n\n";
            $message.= print_r(debug_backtrace(), true);
            
			if (in_array('SKIDDER', $ERROR_REPORTING)) {
				$skidder = curl_init(SKIDDER_URL);
				curl_setopt($skidder, CURLOPT_POST,           true);
				curl_setopt($skidder, CURLOPT_HEADER,         true);
				curl_setopt($skidder, CURLOPT_RETURNTRANSFER, true);
				curl_setopt($skidder, CURLOPT_SSL_VERIFYPEER, false);
				curl_setopt($skidder,
							CURLOPT_POSTFIELDS,
							['application_id' => SKIDDER_APPLICATION_ID,
                             'script'         => $script,
                             'type'           => $exception->getMessage(),
                             'message'        => $message]);
				curl_exec($skidder);
			}
		}
	}
}
