import java.util.*;
import java.io.*;
class BinarySearch {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    System.out.println("Enter the array in sorted order");
    for(int i = 0; i<n; i++)
      a[i] = sc.nextInt();
    int low = 0;
    int high = n-1;
    int key = sc.nextInt();
    int ans = -1;
    while(low<=high) {
      int mid = (low+high)>>1;
      if(a[mid]==key) {
        ans = mid;
        break;
      }
      if(a[mid]<key)
        low = mid+1;
      else
        high = mid-1;
    }
    System.out.println(ans);
  }
}
