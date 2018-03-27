#!/usr/bin/php
<?php
function ft_split($str) {
  $a = preg_split("/[\s]+/", trim($str));
  sort($a, SORT_STRING | SORT_FLAG_CASE);
  return $a;
}
