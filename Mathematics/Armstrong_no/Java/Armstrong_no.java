/*

An armstrong number is a special number where in if all digits of the number are cubed and added, it results in the original number
example:
    153 = 1*1*1 + 5*5*5 + 3*3*3 
    370 = 3*3*3 + 7*7*7 + 0*0*0

The usage of Armstrong numbers are ususlly in data security systems.

The following java program helps us to find whether a number inputted by a user is an armstrong number or not.

*/

import java.util.*;

class Armstrong_no
{
    
    boolean checkArmstrong(int number)
    {
        int temp = number;  // to store a temporary copy of the number
        int sum = 0;        // to store the sum of the cube of the digits
        while(temp > 0)
        {
            int last_digit = temp%10;   // to get the last digit of 'number'
            sum += last_digit * last_digit * last_digit;
            temp /= 10;                 // removing the last digit by truncating the number
        }
        
        if(sum == number)
            return true;
        else
            return false;
    }
    
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input a number : ");
        int number = sc.nextInt();
        
        Armstrong_no object = new Armstrong_no();
        if(object.checkArmstrong(number))
            System.out.println("The number " + number + " is an Armstrong Number");
        else
            System.out.println("The number " + number + " is not an Armstrong Number");
    }
}




// Test this code on the following numbers to see the results : 
//  153
//  407
//  1571
//  1634
