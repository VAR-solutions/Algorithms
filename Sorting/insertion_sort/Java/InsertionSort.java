import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class InsertionSort {

    // Complete the insertionSort2 function below.
    static void insertionSort2(int n, int[] arr) {       
        int swap=0;
        for(int i=1;i<n;i++)
        {
            swap=arr[i];
          for(int j=i-1;j>=0;j--)
              {
              
              if(arr[j]>swap)
              {
                  
                  arr[j+1]=arr[j];
                  arr[j]=swap;
                  
                  
              }
               
          }
            for(int k=0;k<n;k++)
                  {
                      System.out.print(arr[k]+" ");
                  }
              System.out.print("\n");   
        }


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        insertionSort2(n, arr);

        scanner.close();
    }
}
