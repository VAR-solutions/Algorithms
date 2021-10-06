array = [-6,-4,1,2,3,5]
arraySquared = []

let left = 0
let right = array.length-1

for(let i=array.length-1;i>=0;i--){

	if(Math.abs(array[left]>array[right])){
		arraySquared[i] = array[i] * array[i]
		left++
	}	

	else {
		arraySquared[i] = array[i] * array[i]
		right--
	}
}

console.log(arraySquared)
