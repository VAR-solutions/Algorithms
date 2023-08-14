qs :: [Int] -> [Int]
qs [] = []
qs (pivot:cs) = qs [x|x<-cs,x<=pivot] ++ [pivot] ++ qs [y|y<-cs,y>pivot]