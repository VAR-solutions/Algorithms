 def binary_search(a, n, x)
  index_start = 0
  index_end = n - 1

  while index_start <= index_end do
    index_middle = (index_start + index_end) / 2
    if a[index_middle] == x
      return index_middle
    elsif x < a[index_middle]
      index_end = index_middle - 1
    else
      index_start = index_middle + 1
    end
  end
  return "not found"
end

a = [1, 2, 3, 4, 5, 7]
puts binary_search(a, a.size, 3)
