import java.util.Scanner;
/**
 * @author vrajparesh
 *
 */
public class Fractional_Knapsack 
{
    private static double getAns(int maxcap, int[] values, int[] weights) 
    {
        double tValue = 0;                    // Initialize value
        double tWeight = 0;                   // Initialize weight
        while (tWeight <= maxcap) 
        {
            int iofMax = HighestVbyW(values, weights);
            if (tWeight + weights[iofMax] <= maxcap) 
            { 
                tWeight += weights[iofMax];
                tValue += values[iofMax];
            } else 
            {
                double diff = maxcap - tWeight;  // Defining a variable that will be fractioned weight, to be added later.

                tWeight += diff;
                tValue += diff * (values[iofMax] / (double) weights[iofMax]);
            }
            values[iofMax] = 0;
            if (tWeight == maxcap) 
                break;
        }
        return tValue;
    }
    private static int HighestVbyW(int[] values, int[] weights) 
    {
        double currVal = 0;
        double maxVal = 0;
        int iofMax = 0; 
        for (int i = 0; i < values.length; ++i) 
        {
            currVal = values[i] / (double) weights[i];
            if (currVal > maxVal) 
            {
                maxVal = currVal;
                iofMax = i;
            }
        }
        return iofMax;
    }
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();           // Gets number of objects from User
        int maxcap = sc.nextInt();      // Gets the Knapsack capacity allowed from user
        int[] values = new int[n]; 
        int[] weights = new int[n];
        for (int i = 0; i < n; i++) 
        {
            values[i] = sc.nextInt();   // Gets the value for the ith object
            weights[i] = sc.nextInt();  // Gets the weight for the ith object
        }
        System.out.println(getAns(maxcap, values, weights));
        sc.close();
    }
}
