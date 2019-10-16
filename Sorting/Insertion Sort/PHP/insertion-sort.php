<?php

$arr = [5, 2, 4, 1, 3];

/**
 * Ascending Insertion Sort
 */
for ($i = 1; $i < count($arr); $i++) {
    $key = $arr[$i];
    $previousIndex = $i - 1;

    while ($previousIndex >= 0 && $arr[$previousIndex] > $key) {
        $arr[$previousIndex + 1] = $arr[$previousIndex];
        $previousIndex--;
    }

    $arr[$previousIndex + 1] = $key;
}

echo '<pre>' . print_r($arr, true) . '</pre>';