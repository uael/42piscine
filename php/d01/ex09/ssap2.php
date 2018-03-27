#!/usr/bin/php
<?php
array_shift($argv);
$a = [];
$b = [];
$c = [];
foreach ($argv as $arg) {
  $arr = preg_split("/[\s]+/", trim($arg));
  foreach ($arr as $word) {
    if (($word[0] >= 'a' && $word[0] <= 'z') || ($word[0] >= 'A' && $word[0] <= 'Z'))
      $a[] = $word;
    else if ($word[0] >= '0' && $word[0] <= '9')
      $b[] = $word;
    else
      $c[] = $word;
  }
}
sort($a, SORT_STRING | SORT_FLAG_CASE);
sort($b, SORT_STRING | SORT_FLAG_CASE);
sort($c, SORT_STRING | SORT_FLAG_CASE);
foreach ($a as $word) echo $word.PHP_EOL;
foreach ($b as $word) echo $word.PHP_EOL;
foreach ($c as $word) echo $word.PHP_EOL;
