<?php
/**
 * @copyright 2021 City of Bloomington, Indiana
 * @license https://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
declare (strict_types=1);
/**
 * Where on the filesystem this application is installed
 */
define('APPLICATION_HOME', __DIR__);
define('VERSION', trim(file_get_contents(APPLICATION_HOME.'/VERSION')));

/**
 * SITE_HOME is the directory where all site-specific data and
 * configuration are stored.  For backup purposes, backing up this
 * directory would be sufficient for an easy full restore.
 */
define('SITE_HOME', !empty($_SERVER['SITE_HOME']) ? $_SERVER['SITE_HOME'] : __DIR__.'/data');
include SITE_HOME.'/site_config.php';
/**
 * Enable autoloading for the PHP libraries
 */
require APPLICATION_HOME.'/vendor/autoload.php';

if (defined('GRAYLOG_DOMAIN') && defined('GRAYLOG_PORT')) {
    $graylog = new Application\Models\GraylogWriter(GRAYLOG_DOMAIN, GRAYLOG_PORT);
    $logger  = new Laminas\Log\Logger();
    $logger->addWriter($graylog);
    Laminas\Log\Logger::registerErrorHandler($logger);
    Laminas\Log\Logger::registerExceptionHandler($logger);
    Laminas\Log\Logger::registerFatalErrorShutdownFunction($logger);
}
