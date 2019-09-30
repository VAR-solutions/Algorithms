function fibonacci(x::Int)
  if x <= 1
      return x
  else
      return fibonacci(x - 1) + fibonacci(x - 2)
  end
  return 0
end
