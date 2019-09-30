def selection_sort(a, n)
    (0..n - 2).each do |i|
      i_min = i
      (i + 1..n - 1).each do |j|
        if a[j] < a[i_min]
          i_min = j
        end
      end
  
      temp = a[i]
      a[i] = a[i_min]
      a[i_min] = temp
      #byebug
    end
    a
  end
  
  a = [2,7,4,1,5,3]
  selection_sort(a, a.size)
