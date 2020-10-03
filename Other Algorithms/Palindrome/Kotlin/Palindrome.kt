fun main() {
    var n: Int
    var num: Int
    var digit: Int
    var rev: Int = 0

    print("Enter a positive number: ")
    num = readLine()!!.toInt()

    n = num

    do {
        digit = num % 10
        rev = (rev * 10) + digit
        num = num / 10
    }while (num != 0)

    println("The reverse of the number is: $rev")

    if (n == rev){
        println("The number is a palindrome")
    }else{
        println("The number is not a palindrome")
    }
}
