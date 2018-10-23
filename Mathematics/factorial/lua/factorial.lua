-- calculates the factorial of n using loop iteration
function factorial(n)
  local result = 1

  for i = 1, n do
    result = result * i
  end

  return result
end

io.write(factorial(5))
