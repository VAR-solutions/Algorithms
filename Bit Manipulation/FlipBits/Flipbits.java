import java.math.*; 
  
public class Flipbits { 
  
    public static void main(String[] args) 
    { 
        // Creating  BigInteger object 
        BigInteger biginteger = new BigInteger("5482549"); 
  
        // Creating an int i for index 
        int i = 5; 
  
        // Call flipBit() method on bigInteger at index i 
        // store the return BigInteger 
        BigInteger changedvalue = biginteger.flipBit(i); 
  
        String result = "After applying flipBit at index " + i + 
        " of " + biginteger+ " New Value is " + changedvalue; 
  
        // Print result 
        System.out.println(result); 
    } 
} 
