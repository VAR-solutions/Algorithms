import java.util.Arrays;

public class insertionSort {
  public static void main(String[] args) {
    int[] data = { 1, 9, 6, 4, 10, 8, 2, 5, 7, 3};
    System.out.println("Before: " + Arrays.toString(data));
    data = sort(data);
    System.out.println("After:  " + Arrays.toString(data));
  }

  // insertion sort algorithm
  public static int[] sort(int[] data) {
    for (int i = 1; i < data.length; i++) {
      int val = data[i];
      int j = i;

      while ((j > 0) && (val < data[j - 1])) {
        data[j] = data[j - 1];
        j--;
      }

      data[j] = val;
    }

    return data;
  }
}
