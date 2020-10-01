qsSmall [] = []
qsSmall (pivot:tails) = 
    let (smaller, bigger) = partition pivot tails ([], [])
    in qsSmall smaller ++ [pivot] ++ qsSmall bigger

partition :: Int -> [Int] -> ([Int],[Int]) -> ([Int],[Int])
partition _ [] result = result
partition p (a:as) (smaller, bigger)
  | a <= p   = partition p as (a:smaller, bigger)
  | a > p    = partition p as (smaller, a:bigger)