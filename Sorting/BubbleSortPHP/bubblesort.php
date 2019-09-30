<?php

function bubble_sort($array) {
	for ($x = 0;$x < count($array);$x++) {
		for ($y = 0;$y < count($array) - $x - 1;$y++) {
			if ($array[$y] > $array[$y + 1]) {
				$temp = $array[$y];
				$array[$y] = $array[$y + 1];
				$array[$y + 1] = $temp;
	}
}
	echo ("After #" . $x . " run:   ");
	print_array($array);
	}
}
function print_array($array) {
	for ($x = 0;$x < count($array);$x++) {
		echo ($array[$x] . " ");
	}
	echo ("\n");
}

$array = [34, 22, 1, 8, 2, 13];
echo "Original Array: ";
print_array($array);
bubble_sort($array);

?>