#!/usr/bin/php
<?php
if ($argc > 1)
{
    date_default_timezone_set('Europe/Paris');
    setlocale(LC_TIME, 'fr_FR.utf8','fra');
    if (!($date = \DateTime::createFromFormat("D d F Y h:i:s", $argv[1], new \DateTimeZone("Europe/Paris"))))
        echo "Wrong Format".PHP_EOL;
    else
        echo $date->getTimestamp().PHP_EOL;
}
