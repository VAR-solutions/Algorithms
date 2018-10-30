import java.util.*;

public class Solution {

    static String gameOfStones(int n) {

        //  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        //    1 1 1 1 1     1 1  1  1  1
        //  2           2 2               2  2
        //There is a pattern

        int rest = n % 7;
        if(rest < 2 ){
            return "Second";
        }else{
            return "First";
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        int t = scanner.nextInt();

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();

            String result = gameOfStones(n);
            System.out.println(result);
        }

        scanner.close();
    }
}
