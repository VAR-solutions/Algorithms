# Linear Search: it searchs a value by going accross the array
def linear_search(array, value)
  if array.index(value).nil?
    return -1
  else
    return array.index(value)
  end
end

# TEST
array = Array.new
array = [7,8,1,3,4,10]
  
puts linear_search(array, 4)
 