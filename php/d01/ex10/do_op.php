#!/usr/bin/php
<?php
if ($argc != 4)
    exit("Incorrect Parameters".PHP_EOL);
$a = trim($argv[1]);
$o = trim($argv[2]);
$b = trim($argv[3]);
if (!is_numeric($a) || !is_numeric($a) || !in_array($o, ['+', '-', '*', '/', '%']))
  exit("Incorrect Parameters".PHP_EOL);
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
