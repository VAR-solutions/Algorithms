import java.io.*; 
import java.util.*; 

class Kadane{ 
	public static void main (String[] args){ 
		int [] a = {7, -2, 3, -8, 6, 2, 1}; 
		System.out.println("Maximum contiguous sum is " + maxSubArraySum(a)); 
	} 

	static int maxSubArraySum(int a[]){ 
		int sz = a.length, ans = Integer.MIN_VALUE, sum = 0; 

		for (int i = 0; i < sz; i++){ 
			sum = sum + a[i]; 
			
			if (ans < sum) 
				ans = sum; 
				
			if (sum < 0) 
				sum = 0; 
		} 
		return ans; 
	} 
} 

