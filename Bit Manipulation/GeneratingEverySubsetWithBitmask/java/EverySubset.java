/**
 * Generates every subset of the array.
 * For e.g.
 * array = [1, 2, 3]
 * Outputs:
 * 1
 * 2
 * 1 2 
 * 3
 * 1 3 
 * 2 3
 * 1 2 3
 */   
import java.util.Scanner;

class EverySubset{

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Input your array size : ");
        int n = scanner.nextInt();

        int[] array = new int[n];
        System.out.println("Please enter the "+n+" elements :");
        for(int i = 0; i < n; i++){
            array[i] = scanner.nextInt();
        }

        System.out.println("All subsets of array are : ");
        allSubsets(array, n);
    }

    private static void allSubsets(int[] array, int n){
        int totalSubsetCoount = (1 << n); //For an array of size n, there can be a total of 2^n subsets.

        for(int i = 0; i < totalSubsetCoount; i++){
            for(int j = 0; j < n; j++) {
                // If the jth bit in the number i is 1,
                // then jth element of array must be included in the present subset.
                if((i & (1 << j)) != 0) {
                    System.out.print(array[j] + " ");
                }
            }

            System.out.println();
        }
    }
}