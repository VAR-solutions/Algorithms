max_prime_number = 100;
var primes =2
for ( var i = 2; i++ < max_prime_number; ) {
    for (var j = 2 ; i % j++; ) {
        j - i ? primes : (primes += ", " + i)
    }
};
console.log(primes);
