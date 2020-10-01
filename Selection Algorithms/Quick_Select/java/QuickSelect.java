/**
 * Quick-select implementation in java.
 * Selection of pivot has been done using a randomized selection.
 * Amortized worst case time complexity of O(N), where N = size of array.
 */
import java.util.Scanner;
import java.util.Random;

class QuickSelect {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input your array size : ");
        int n = scanner.nextInt();
        int[] array = new int[n];
        System.out.println("Please enter the "+n+" elements :");
        for(int i = 0; i < n; i++){
            array[i] = scanner.nextInt();
        }

        System.out.println("Enter the value of k : ");
        int k = scanner.nextInt();
        System.out.println("The kth element is : " + kthElement(array, 0, n - 1, k));
    }

    private static int kthElement(int[] nums, int low, int high, int k){
        Random random = new Random();
        while(low < high){
            int idx = low + random.nextInt(high - low);
            int j = partition(nums, low, high, idx);
            if(j == k - 1) return nums[j];
            else if(j < k - 1) low = j + 1;
            else high = j - 1; 
        }
        return nums[low];
    }
    
    private static int partition(int[] nums, int low, int high, int idx){
        int pivot = nums[idx];
        swap(nums, idx, high);
        int j = low;
        
        for(int i = low; i <= high; i++){
            if(nums[i] < pivot){
                swap(nums, i, j);
                j++;
            }
        }
        
        swap(nums, high, j);
        return j;
    }

    private static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
