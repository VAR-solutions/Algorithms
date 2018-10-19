// Un función booleana que devuelve true o false si la palabra es palindrome

function isPalindrome(str) {
     var wordTest = str.replace(/[^a-zA-Z0-9]/g,"").toUpperCase().split("");
  return wordTest.toString() === wordTest.reverse().toString() ;
}

console.log(isPalindrome("eye"));
