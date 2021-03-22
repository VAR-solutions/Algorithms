#!/bin/bash

# Bubble Sort :: Time : O(n ^ 2)


# Creating an array
a=(200 100 300 700 600 500)
n=6 

echo "Array Before Sorting: "
echo ${a[*]}


for ((i = 0; i < n; ++i))
do
	# initialized boolean check as false
	check=false
	for ((j = 0; j < n - i - 1; ++j))
	do
		if [ ${a[j]} -gt ${a[$((j + 1))]} ]
		then 
			temp=${a[j]}
			a[$j]=${a[$((j + 1))]}
			a[$((j + 1))]=$temp
			
			# Swap occurred in inner loop 
			check=true
		fi
	done
	
	# if no two elements were swapped by inner loop  , then break 
	if [ "$check" = false ] ; then
		break
	fi
done

echo
echo "Array After Sorting:"
echo ${a[*]}






















