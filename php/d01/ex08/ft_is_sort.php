#!/usr/bin/php
<?php
function ft_is_sort($arr) {
    $sort = $arr;
    sort($sort, SORT_STRING);
    return count(array_diff_assoc($sort, $arr)) == 0;
}
