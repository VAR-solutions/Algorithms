#!/bin/bash

# Creating an array
a=(200 100 300 700 600 500)
n=6

echo "Array Before Sorting: "
echo ${a[*]}

for ((i = 0; i < n; ++i))
do
	for ((j = 0; j < n - i - 1; ++j))
	do
		if [ ${a[j]} -gt ${a[$((j + 1))]} ]
		then 
			temp=${a[j]}
			a[$j]=${a[$((j + 1))]}
			a[$((j + 1))]=$temp
		fi
	done
done

echo
echo "Array After Sorting:"
echo ${a[*]}


