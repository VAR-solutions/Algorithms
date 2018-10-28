a = [9,8,6,11,10,3,1,2,13,50]
  n = a.size-1
  0.upto(n - 1) do |i|
    min_idx = i
    (i + 1).upto(n) { |j| min_idx = j if a[j] < a[min_idx] }
    a[i], a[min_idx] = a[min_idx], a[i] # unless min.eql?(i)
  end

puts a

