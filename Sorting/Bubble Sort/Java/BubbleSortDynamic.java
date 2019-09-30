#Blazing21
#Indonesia

import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int a;
    System.out.print( "Range data : ");
    a=scan.nextInt();
      int[] data = new int[a];
        for( int i = 0; i < data.length; i++ ){
            System.out.print("data-" + i + ": ");
            data[i] = scan.nextInt();
        }
    System.out.println("Before Sort: " + Arrays.toString(data));
    data = sort(data);
    System.out.println("After Sort:  " + Arrays.toString(data));
  }

  // bubble sort algorithm
  public static int[] sort(int[] data) {
    for (int i = 0; i < data.length; i++) {
      for (int j = 0; j < data.length - 1; j++) {
        if (data[j] > data[j + 1]) {
          int temp    = data[j];
          data[j]     = data[j + 1];
          data[j + 1] = temp;
        }
      }
    }

    return data;
  }
}
