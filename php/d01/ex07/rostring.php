#!/usr/bin/php
<?php
if ($argc > 1) {
  $ret = preg_split("/[\s]+/", trim($argv[1]));
  $oops = array_shift($ret);
  foreach ($ret as $word)
      echo $word.' ';
  echo $oops.PHP_EOL;
}
