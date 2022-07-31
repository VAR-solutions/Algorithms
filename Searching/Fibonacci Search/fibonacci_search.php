<?php

/**
 * Fibonacci Search
 *
 * @param array $arr - array of numbers
 * @param int $x - value to search
 * @param int $n - size of array
 * @return int|mixed
 */
function fibonacci_search($arr, $x, $n)
{
	// Initialiaze fibonacci numbers
	$fib2 = 0; // (m-2)'th Fibonacci No
	$fib1 = 1; // (m-1)'th Fibonacci No
	$fibM = $fib2 + $fib1; // m'th Fibonacci

	/* fibM is going to store the smalltest Fibonacci Number
	greater than or equal to n */
	while ($fibM < $n) {
		$fib2 = $fib1;
		$fib1 = $fibM;
		$fibM = $fib2 + $fib1;
	}

	// Marks the eliminated range from front
	$offset = -1;

	/* while there are elements to be inspected. Note that 
	we compare arr[fib2] with x. When fibM becomes 1, fib2 becomes 0 */
	while ($fibM > 1) {
		// Check if $fib2 is a valid location
		$i = min(($offset + $fib2), $n-1);

		/* If x is greater than the value at index fib2, 
		cut the subarray array from offset to i */
		if ($arr[$i] < $x) {
			$fibM = $fib1;
			$fib1 = $fib2;
			$fib2 = $fibM - $fib1;
			$offset = $i;
		}
		/* If x is greater than the value at index fib2, 
		cut the subarray after i+1  */
		else if ($arr[$i] > $x) {
			$fibM = $fib2;
			$fib1 -= $fib2;
			$fib2 = $fibM - $fib1;
		} 
		// element found. return index
		else return $i;
	}

	// comparing the last element with x
	if ($fib1 && $arr[$offset+1] == $x) {
		return $offset + 1;
	}

	// element not found. return -1
	return -1;
}

$arr = [10,22,35,40,45,50,80,82,85,90,100];
$n = 11;
$x = 85;

printf("Found at index: %d\n", fibonacci_search($arr, $x, $n));