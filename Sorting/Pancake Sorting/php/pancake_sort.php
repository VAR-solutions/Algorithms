<?php 
// PHP program to 
// sort array using 
// pancake sort 

/* Reverses arr[0..i] */
function flip(&$arr, $i) 
{ 
	$start = 0; 
	while ($start < $i) 
	{ 
		$temp = $arr[$start]; 
		$arr[$start] = $arr[$i]; 
		$arr[$i] = $temp; 
		$start++; 
		$i--; 
	} 
} 

// Returns index of the 
// maximum element in 
// arr[0..n-1] 
function findMax($arr, $n) 
{ 
	$mi = 0; 
	for ($i = 0; $i < $n; ++$i) 
		if ($arr[$i] > $arr[$mi]) 
				$mi = $i; 
	return $mi; 
} 

// The main function that 
// sorts given array using 
// flip operations 
function pancakeSort(&$arr, $n) 
{ 
	// Start from the complete 
	// array and one by one 
	// reduce current size 
	// by one 
	for ($curr_size = $n; $curr_size > 1; --$curr_size) 
	{ 
		// Find index of the 
		// maximum element in 
		// arr[0..curr_size-1] 
		$mi = findMax($arr, $curr_size); 

		// Move the maximum 
		// element to end of 
		// current array if 
		// it's not already 
		// at the end 
		if ($mi != $curr_size-1) 
		{ 
			// To move at the end, 
			// first move maximum 
			// number to beginning 
			flip($arr, $mi); 

			// Now move the maximum 
			// number to end by 
			// reversing current array 
			flip($arr, $curr_size-1); 
		} 
	} 
} 

// A utility function to print 
// n array of size n 
function printArray($arr, $n) 
{ 
	for ($i = 0; $i < $n; ++$i) 
		print($arr[$i]." "); 
} 

// Driver code 
$arr = array(23, 10, 20, 11, 12, 6, 7); 
$n = count($arr); 

pancakeSort($arr, $n); 

echo("Sorted Array \n"); 
printArray($arr, $n); 

return 0; 
	
// This code is contributed by vidz-1
?> 
<!--  -->