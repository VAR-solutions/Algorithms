import java.math.*;
import java.util.*;

public class Solution {

    static int minimumAbsoluteDifference(int[] arr) {
        Arrays.sort(arr);
        int minVal = Math.abs(arr[0]-arr[1]);
        for(int i = 2; i < arr.length ; i++){
            int dif = Math.abs(arr[i-1]-arr[i]);
            if(minVal > dif ){
                minVal = dif;
            }
        }
        return minVal;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        int n = scanner.nextInt();

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = minimumAbsoluteDifference(arr);

        System.out.println(result);

        scanner.close();
    }
}
