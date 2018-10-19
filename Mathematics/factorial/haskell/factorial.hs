fat :: Int -> Int
fat 1 = 1
fat n = fat (n -1) * n