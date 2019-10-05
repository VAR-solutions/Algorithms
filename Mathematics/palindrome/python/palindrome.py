import re, string

# Validates if a string with all punctuation removed
# reads the same backwards as forwards
def palindrome(str):
    # Convert string to lower case and emove all non-word characters
    sanitized_str = re.sub('\W', '', str.lower())
    return sanitized_str == sanitized_str[::-1]

strs = [
  'eye',
  'race car',
  'not a palindrome',
  'A man, a plan, a canal. Panama',
  'never odd or even',
  'nope',
  'My age is 0, 0 si ega ym.',
]
for str in strs:
    print("%s\t| %s" % (palindrome(str), str))
