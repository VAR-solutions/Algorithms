import java.util.Arrays;

public class BubbleSort {
  public static void main(String[] args) {
    int[] data = { 1, 9, 6, 4, 10, 8, 2, 5, 7, 3 };
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
