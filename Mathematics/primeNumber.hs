module PrimeNumber where

--This code is used to validate whether an N number is prime
-- Run the function "main" and type a number

-- Receive a number and check if it has only one divisor
isPrime :: (Int, Int) -> Bool
isPrime(number, divider)
    | number == 1 = True
    | divider == 1 = True
    | mod number divider == 0 = False
    | otherwise = isPrime(number, divider-1)

--Checks whether an operation was successful
checkOperation :: (Bool) -> Maybe Bool
checkOperation(operation)
    |operation = Just True
    |otherwise = Nothing


--Function main
main :: IO()
main = do
        putStr "Type a Number >> "
        n <- getLine
        case checkOperation(isPrime(read n :: Int, (read n :: Int)-1)) of
            Just True -> putStr("The number " ++ n ++ " is prime \n")
            Nothing -> putStr("The number " ++ n ++ " isn't prime \n")

