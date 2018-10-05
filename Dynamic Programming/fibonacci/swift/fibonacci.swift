func fib(_ n:Int) -> Int {
  if n == 0 {
    return 0 // Special case for 0
  }

  // Initial values of fibonacci series
  var f = [1, 1]

  for i in 2..<n {
    // Use modulus to switch array indexes
    f[i%2] = f[0] + f[1]
  }

  return f[(n+1)%2]
}

let n = 9
print(fib(n))
