# BogoSort also known as permutation sort, stupid sort, slow sort, shotgun sort
# or monkey sort is a particularly ineffective algorithm based on generate and
# test paradigm. The algorithm successively generates permutations of its input
# until it finds one that is sorted.

def sorted?(ary)
  0.upto(ary.size - 2).all? { |n| ary[n] <= ary[n + 1] }
end

def bogosort(ary)
  until sorted?(ary)
    ary.shuffle!
  end

  ary
end

test_array = Array.new(10) { rand(100) }
bogosort(test_array)
puts "Sorted array: #{test_array}"
puts "Correct? #{test_array == test_array.sort}"