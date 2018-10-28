#!/bin/bash

function fibonacci {

	local n=$1

	[[ $n == 0 ]] && echo $n && return
	[[ $n == 1 ]] && echo $n && return
	
	local x=$(fibonacci $((n - 1)))
	local y=$(fibonacci $((n - 2)))

	echo $((x + y))
}

echo -e sh\\t$(fibonacci 10)
