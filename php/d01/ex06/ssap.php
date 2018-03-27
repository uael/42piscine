#!/usr/bin/php
<?php
array_shift($argv);
$ret = [];
foreach ($argv as $arg) {
  $ret = array_merge($ret, preg_split("/[\s]+/", trim($arg)));
}
sort($ret);
foreach ($ret as $word) echo $word.PHP_EOL;
