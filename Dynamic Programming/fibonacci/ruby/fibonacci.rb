def fib(n)
  return 0 unless n.positive? # Special case for 0

  # Initial values of fibonacci series
  f = [1, 1]

  (2..n).each do |i|
    # Use modulus to switch array indexes
    f[i%2] = f.sum
  end

  f[(n+1)%2]
end

n = 9
puts fib n
