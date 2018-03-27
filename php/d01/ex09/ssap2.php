#!/usr/bin/php
<?php
array_shift($argv);
$a = [];
$b = [];
$c = [];
foreach ($argv as $arg) {
  $arr = preg_split("/[\s]+/", trim($arg));
  foreach ($arr as $word) {
    if (ctype_alpha($word[0]))
      $a[] = $word;
    else if (ctype_digit($word[0]))
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
