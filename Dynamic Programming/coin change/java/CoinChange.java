import java.io.*;
import java.util.*;
class CoinChange {
	public static void main (String[] args) {
	    
	    //taking input using Scanner class
		Scanner sc=new Scanner(System.in);
		
		//taking total count of testcases
		int testcases=sc.nextInt();
		while(testcases-->0)
		{
		    //taking value
		    int value=sc.nextInt();
		    
		    //taking number of coins
		    int numberOfCoins=sc.nextInt();
		    int coins[]=new int[numberOfCoins];
		    
		    //adding coins to the array
		    for(int i=0;i<numberOfCoins;i++)
		    {
		        int x=sc.nextInt();
		        coins[i]=x;
		    }
		    
		    //creating an object of class Geeks
		    Geeks obj=new Geeks();
		    
		    //calling minimumNumberOfCoins() method of class Geeks
		    long answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
		    
		    //printing "Not Possible" if answer is -1,
		    //else printing answer
		    System.out.println(answer==-1?"Not Possible":answer);
		}
	}
}


 // } Driver Code Ends


class Geeks
{
    //Complete this function
    public long minimumNumberOfCoins(int coins[],int m,int V)
    {
        // your code here
         int table[] = new int[V + 1]; 
         table[0] = 0;
         
         for (int i = 1; i <= V; i++) 
        table[i] = Integer.MAX_VALUE;
        
        for (int i = 1; i <= V; i++) 
        { 
            // Go through all coins smaller than i 
            for (int j = 0; j < m; j++) 
            if (coins[j] <= i) 
            { 
                int sub_res = table[i - coins[j]]; 
                if (sub_res != Integer.MAX_VALUE  
                       && sub_res + 1 < table[i]) 
                       table[i] = sub_res + 1; 
                         
                  
            } 
              
        } 
        if (table[V] != Integer.MAX_VALUE)
            return table[V];
        return -1;
    }
}
