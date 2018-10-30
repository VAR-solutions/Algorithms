fib  :: Int -> Int 
fib n | n == 1  = 1
      | n == 0 = 0
      | otherwise = fib(n-1) + fib(n-2)