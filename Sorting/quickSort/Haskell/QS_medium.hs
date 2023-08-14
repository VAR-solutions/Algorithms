qsMedium :: [Int] -> [Int]
qsMedium [] = []
qsMedium (c:cs) = qsMedium (compare c cs (>=)) ++ [c] ++ qsMedium (compare c cs (<))
  
compare :: Int -> [Int] -> (Int -> Int -> Bool) -> [Int]
compare pivot [] cmp = []
compare pivot (a:as) cmp 
  | cmp pivot a  = a : compare pivot as cmp
  | otherwise = compare pivot as cmp