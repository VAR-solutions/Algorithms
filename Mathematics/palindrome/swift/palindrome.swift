import Foundation

// Validates if a string with all punctuation removed
// reads the same backwards as forwards
func palindrome(_ str:String) -> Bool {
  // Convert string to lower case and emove all non-word characters
  let sanitizedStr = str.lowercased().replacingOccurrences(of: "\\W", with: "", options: .regularExpression)
  return sanitizedStr == String(sanitizedStr.reversed())
}

let strs = [
  "eye",
  "race car",
  "not a palindrome",
  "A man, a plan, a canal. Panama",
  "never odd or even",
  "nope",
  "My age is 0, 0 si ega ym.",
]
for str in strs {
  print("\(palindrome(str))\t| \(str)")
}
