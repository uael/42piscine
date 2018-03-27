#!/usr/bin/php
<?php
if ($argc == 2) {
    echo trim(preg_replace('/\s{2,}/', ' ', $argv[1])).PHP_EOL;
}