# Validates if a string with all punctuation removed
# reads the same backwards as forwards
def palindrome?(str)
  # Convert string to lower case and emove all non-word characters
  sanitized_str = str.downcase.gsub(/\W/, '')
  sanitized_str == sanitized_str.reverse
end

strs = [
  'eye',
  'race car',
  'not a palindrome',
  'A man, a plan, a canal. Panama',
  'never odd or even',
  'nope',
  'My age is 0, 0 si ega ym.',
]
strs.each do |str|
  puts "#{palindrome?(str)}\t| #{str}"
end
