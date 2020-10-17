// A Java program to find LCM of two numbers
class LCM
{
	// Recursive method to return HCF of a and b
	static int HCF(int a, int b)
	{
		if (a == 0)
			return b; 
		return HCF(b % a, a); 
	}
	
	// method to return LCM of two numbers
	static int LCM(int a, int b)
	{
		return (a / HCF(a, b)) * b;
	}
	
	//Main method
	public static void main(String[] args) 
	{
		int a = 15, b = 20;
		System.out.println("LCM of " + a + " and " + b + " is " + LCM(a, b));
	}
}
