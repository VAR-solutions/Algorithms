qsBig :: [Int] -> [Int]
qsBig [] = []
qsBig (c:cs) = qsBig (smaller c cs) ++ [c] ++ qsBig (bigger c cs)

smaller :: Int -> [Int] -> [Int]
smaller pivot [] = []
smaller pivot (a:as)
  | pivot >= a  = a : smaller pivot as
  | otherwise = smaller pivot as

bigger :: Int -> [Int] -> [Int]
bigger pivot [] = []
bigger pivot (a:as)
  | pivot < a  = a : bigger pivot as
  | otherwise = bigger pivot as