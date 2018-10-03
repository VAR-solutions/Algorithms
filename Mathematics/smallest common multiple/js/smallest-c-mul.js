// Find the smallest common multiple of the given parameters that can be evenly divided by both, as well as 
// by all numbers in the range between these parameters.
// The range is an array of two numbers, not necessarily be in numerical order.

function smallestCommons(arr) {
  arr.sort(function(a, b) {                             //sorting given numbers
    return b - a;
  });
 
  var num = [];
  for (var i = arr[0]; i >= arr[1]; i--) {              //create array of all nums
    num.push(i);
  }
  
  var quot = 0; //variables for the quotient that can access them outside the loop
  var loop = 1;
  var n;
  // Run code while n is not the same as the array length.
  do {
    quot = num[0] * loop * num[1];
    for (n = 2; n < num.length; n++) {
      if (quot % num[n] !== 0) {
        break;
      }
    }
    loop++;
  } while (n !== num.length);

 return quot;
}

smallestCommons([1,5]);       //Example of given numbers
