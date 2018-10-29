import java.util.*;

public class CountingSort{
	//O(nlogn)
	public static void main(String[] args){
		int [] data= {10,23,53,22,1,1,100,32,58,34,42,64}; 
		countingSort(data);
		System.out.println(Arrays.toString(data));
	}
	
	static int[] countingSort(int[] a) {
		int max = a[0], min = a[0];
        for (int i = 1; i < a.length; i++)
        {
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
                min = a[i];
        }
        int range = max - min + 1;
 
        int[] count = new int[range];
        /** make count/frequency array for each element **/
        for (int i = 0; i < a.length; i++)
            count[a[i] - min]++;
        /** modify count so that positions in final array is obtained **/
        for (int i = 1; i < range; i++)
            count[i] += count[i - 1];
        /** modify original array **/
        int j = 0;
        for (int i = 0; i < range; i++)
            while (j < count[i])
                a[j++] = i + min;
			
		return a;
    }
	
}	