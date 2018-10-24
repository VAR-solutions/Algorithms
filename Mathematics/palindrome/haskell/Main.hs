module Main where 

import Palindrome

main :: IO()
main = do 
    print $ ispalindrome 100
    print $ ispalindrome 101

    print $ ispalindromeStrings "woop"
    print $ ispalindromeStrings "woopoow"

