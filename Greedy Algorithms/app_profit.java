import java.util.Arrays;
class solution {

	public static int maximumProfit(int budget[]) {
		// Write your code here
		Arrays.sort(budget);
      int ans = 0;
      	for(int i = 0; i < budget.length; i++)
        {
         	ans = Math.max(ans, budget[i]*(budget.length - i));
        }
      return ans;
	}
  	public static void quicksort(int[] input, int start, int end)
    {
      if(start<0 || end >= input.length || start>=end) return;
      int i = start+1;
      for(int j = start+1; j <= end; j++)
      {
        if(input[j]<=input[start])
        {
          input[j] = input[j] + input[i];
          input[i] = input[j] - input[i];
          input[j]-=input[i];
          i++;
        }
      }
      input[start] = input[start] + input[i];
      input[i] = input[start] - input[i];
      input[start]-=input[i];
      quicksort(input, start, i-2);
      quicksort(input, i, end);
    }

}
import java.util.Scanner;

public class app_profit {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int input[] = new int[n];
		for(int i=0;i<n;i++)
			input[i] = s.nextInt();
		
		System.out.println(solution.maximumProfit(input));
	}

}

