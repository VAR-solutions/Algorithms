class Array
    def counting_sort!
      replace counting_sort
    end
   
    def counting_sort
      min, max = minmax
      count = Array.new(max - min + 1, 0)
      each {|number| count[number - min] += 1}
      (min..max).each_with_object([]) {|i, ary| ary.concat([i] * count[i - min])}
    end
  end
   
  ary = [9,7,10,2,9,7,4,3,10,2,7,10,2,1,3,8,7,3,9,5,8,5,1,6,3,7,5,4,6,9,9,6,6,10,2,4,5,2,8,2,2,5,2,9,3,3,5,7,8,4]
  p ary.counting_sort.join(",")
 
  p ary = Array.new(20){rand(-10..10)}
  p ary.counting_sort
