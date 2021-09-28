using System;

public class Test
{
	public static void Main()
	{
		int[] arr=new int[15]{-1,0,5,6,-2,8,3,-5,-1,0,6,-2,-8,3,-5};

    int maxSum=arr[0],currentSum=0;

    for(int i=0;i<15;i++)
    {
        if(currentSum+arr[i]>0)
        {
          currentSum+=arr[i];   //Keeps tack of sum of current subarray 
        }
        else{
            currentSum=0;
        }
        if(maxSum<currentSum)
        {
        	maxSum=currentSum;  //Update maximum sum
        }
     

    }
    Console.WriteLine(maxSum);
	}
}
