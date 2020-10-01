def cycle_sort(array, swaps)
    swaps = 0
    cycle_start = 0

    while cycle_start < array.length - 1
        number_to_swap = array[cycle_start]
        position = cycle_start

        i = cycle_start + 1
        while i < array.length
            if array[i] < number_to_swap
                position += 1
            end
            i += 1
        end

        if position != cycle_start
            while number_to_swap == array[position]
                position += 1
            end

            array[position], number_to_swap = number_to_swap, array[position]
            swaps += 1
        end

        while position != cycle_start
            position = cycle_start

            j = cycle_start + 1
            while j < array.length - 1
                if array[j] < number_to_swap
                    position += 1
                end

                while number_to_swap == array[position]
                    position += 1
                end

                j += 1
            end

            array[position], number_to_swap = number_to_swap, array[position]
            swaps += 1
        end

        cycle_start += 1
    end

    return array, swaps

end

print(cycle_sort([120, 20, 12, 1, 5, 5, 78], [0]))