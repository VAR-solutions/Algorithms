import java.util.Arrays;

public class SelectionSort {
  public static void main(String[] args) {
    int[] data = { 1, 9, 6, 4, 10, 8, 2, 5, 7, 3 };
    System.out.println("Before: " + Arrays.toString(data));
    data = sort(data);
    System.out.println("After:  " + Arrays.toString(data));
  }

  // selection sort algorithm
  public static int[] sort(int[] data) {
    int i, j, min;

    for (i = 0; i < data.length; i++) {
      min = i;

      for (j = i + 1; j < data.length; j++) {
        if (data[j] < data[min]) {
          min = j;
        }
      }

      int temp = data[i];
      data[i] = data[min];
      data[min] = temp;
    }

    return data;
  }
}
