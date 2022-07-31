import java.math.*;
import java.util.*;

public class CakeWalk {

    static long marcsCakewalk(int[] calorie) {

        Arrays.sort(calorie);
        long minMiles = 0;
        //I have run through the revers order of the array because there is not built in method
        // to sort descending order. I just sorted to ascending order and run loop on descending order.
        // I am too lazy. ;)
        for(int i = calorie.length ; i > 0 ; i--){
            minMiles += Math.pow(2,calorie.length - i ) * calorie[i-1];
        }

        return minMiles;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        int n = scanner.nextInt();

        int[] calorie = new int[n];

        String[] calorieItems = scanner.nextLine().split(" ");

        for (int i = 0; i < n; i++) {
            int calorieItem = Integer.parseInt(calorieItems[i]);
            calorie[i] = calorieItem;
        }

        long result = marcsCakewalk(calorie);

        System.out.println(result);

        scanner.close();
    }
}
