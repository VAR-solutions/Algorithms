(function(){
"use strict"

const juggle = function(n) {
	var prev,next
	var result = [];

	prev = n;

	//the first term is n
	result.push(prev);
	//continue until we reach the number 1
	while (prev != 1) {
		next = 0;

		if (prev%2 === 0) { //if even
			//next is the square root of the prev
			next = parseInt(Math.sqrt(prev));
		} else { //if odd
			//next is the prev to the power of 3/2
			next = parseInt(Math.pow(Math.sqrt(prev),3));
		}

		result.push(next);
		prev = next;
	}

	return result;
}

module.exports = juggle;

})();  