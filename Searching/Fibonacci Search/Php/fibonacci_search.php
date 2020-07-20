<?php

/**
 * Fibonacci Search
 */

declare (strict_types = 1);

/**
 * Get minimal value of the array
 *
 * @param  int    $x
 * @param  int    $y
 * @return int
 */
function getMin(int $x, int $y): int
{
    return $x <= $y ? $x : $y;
}

/**
 * Main method
 *
 * @param  array  $args
 * @param  int    $x
 * @param  int    $n
 * @return int
 */
function fib(array $args, int $x, int $n): int
{
    $fibMMm2 = 0;
    $fibMMm1 = 1;
    $fibM    = $fibMMm2 + $fibMMm1;

    while ($fibM < $n) {
        $fibMMm2 = $fibMMm1;
        $fibMMm1 = $fibM;
        $fibM    = $fibMMm2 + $fibMMm1;
    }

    $offset = -1;

    while ($fibM > 1) {
        $i = getMin($offset + $fibMMm2, $n - 1);

        if ($args[$i] < $x) {
            $fibM    = $fibMMm1;
            $fibMMm1 = $fibMMm2;
            $fibMMm2 = $fibM - $fibMMm1;
            $offset  = $i;
        } elseif ($args[$i] > $x) {
            $fibM    = $fibMMm2;
            $fibMMm1 = $fibMMm1 - $fibMMm2;
            $fibMMm2 = $fibM - $fibMMm1;
        } else {
            return $i;
        }
    }

    if ($n < $args[$offset]) {
        return -1;
    }

    if ($fibMMm1 && $args[$offset + 1] == $x) {
        return $offset + 1;
    }
}

$args = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100];

echo "Data Dummy: ";
print_r($args);
echo "Search: ";

/** @loop Get input from terminal */
while ($input = (int) trim(fgets(STDIN))) {
    $res = fib($args, $input, count($args));
    echo $res . "\nSearch: ";
}
