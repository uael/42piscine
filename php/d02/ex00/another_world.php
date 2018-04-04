#!/usr/bin/php
<?php
if ($argc > 1)
  echo implode(' ', preg_split("/[\s]+/", trim($argv[1]))).PHP_EOL;
