/*
 * Function that returns a list of all prime factors of a number 
 */
function  prime_factors(n) {
  let factors = []
  while (n % 2 == 0) {
    factors.push(2);
    n = n / 2; 
  }
  for (let k = 3; k < Math.floor(Math.sqrt(n)) + 1; k = k + 2){
    while (n % k == 0) {
      factors.push(k);
      n = n / k; 
    }
  }
  if ( n > 2){
    factors.push(n);
  }
  return factors;
}


/*
 * Tests
 */

let n = 315;
console.log(prime_factors(n));
