ordernar ::[Int] -> [Int]
ordernar [] = []
ordernar (s:xs) = ordernar [x|x <- xs, (digitsInt (show x)) < (digitsInt (show s))]
                  ++ [s] ++
                  ordernar [x|x <- xs, (digitsInt (show x)) >= (digitsInt (show s))]