def combsort(array, shrink = 1.247330950103979)
  sorted = array.dup
  gap = array.size
  swapped = false

  until gap == 1 && !swapped
    gap = (gap / shrink).to_i
    gap = 1 if gap < 1

    swapped = false

    gap.upto(sorted.size - 1) do |i|
      next if sorted[i - gap] <= sorted[i]

      sorted[i - gap], sorted[i] = sorted[i], sorted[i - gap]
      swapped = true
    end
  end

  sorted
end

# Test case
if $PROGRAM_NAME == __FILE__
  unsorted = Array.new(20) { |_i| rand(10_000) }
  sorted = combsort(unsorted)
  puts "Sorting: #{unsorted}"
  puts "Sorted:  #{sorted}"
  puts "Correct? #{sorted == unsorted.sort}"
end
