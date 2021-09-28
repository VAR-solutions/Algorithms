func sieve(_ n: Int) -> [Bool] {
    var i = 2
    var primes = Array(repeating: true, count: n)
    
    while i < n {
        if primes[i] == true {
            var j = i*i
            while j < n {
                primes[j] = false
                j += i
            }
        }
        i += 1
    }
    
    return primes
}

// Usage
let x = sieve(10)
// Prints all prime numbers till 10
for (i,prime) in x.enumerated() {
    if prime {
        print(i)
    }
}
