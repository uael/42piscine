#!/usr/bin/php
<?php
if ($argc != 2)
    exit("Incorrect Parameters".PHP_EOL);
$r = preg_split("/[\s]*([+\-\*\/%])[\s]*/", trim($argv[1]), -1, PREG_SPLIT_DELIM_CAPTURE);
if (count($r) != 3)
  exit("Syntax Error".PHP_EOL);
$a = trim($r[0]);
$o = trim($r[1]);
$b = trim($r[2]);
if (!is_numeric($a) || !is_numeric($a) || !in_array($o, ['+', '-', '*', '/', '%']))
  exit("Syntax Error".PHP_EOL);
switch ($o) {
  case '+':
    echo ($a + $b);
    break;
  case '-':
    echo ($a - $b);
    break;
  case '*':
    echo ($a * $b);
    break;
  case '/':
    if ($b == 0) exit("Incorrect Parameters".PHP_EOL);
    echo ($a / $b);
    break;
  case '%':
    if ($b == 0) exit("Incorrect Parameters".PHP_EOL);
    echo ($a % $b);
    break;
}
echo PHP_EOL;
