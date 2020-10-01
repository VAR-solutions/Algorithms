def reverse_number(input)
   num = input.to_i
   rev = 0
   while num > 0
      rem = num % 10
      rev = rev * 10 + rem
      num = num / 10
   end 
   rev
end

input = gets.chomp
puts reverse_number(input)

