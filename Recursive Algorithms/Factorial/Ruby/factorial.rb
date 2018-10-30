#!/usr/bin/env ruby
# To test this method, simply run `ruby factorial.rb n`, where n is a positive integer.

# Return n! for a given positive integer.
def factorial(n)
  return 1 if n <= 1
  n * factorial(n - 1)
end

# Print out the factorial of the number passed in via the command line.
puts factorial(ARGV[0].to_i)
