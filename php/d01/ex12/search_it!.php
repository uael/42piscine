#!/usr/bin/php
<?php
if ($argv < 2)
    return ;
array_shift($argv);
$lookup = array_shift($argv);
$arr = [];
foreach ($argv as $arg)
  if (($oops = explode(':', trim($arg))) && count($oops) == 2)
    $arr[$oops[0]] = $oops[1];
if (isset($arr[$lookup]))
  echo $arr[$lookup].PHP_EOL;
