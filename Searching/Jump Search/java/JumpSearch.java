import java.util.Scanner;

public class JumpSearch {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter the length of Array: ");
        int n = scanner.nextInt();

        System.out.println("Enter the element to be searched:");
        int element = scanner.nextInt();

        int jumpSize = (int) Math.ceil(Math.sqrt(n));
        int[] arr = new int[n];

        System.out.println("Enter array elements: ");
        for(int i=0;i<n;i++){
            arr[i] = scanner.nextInt();
        }

        arr = returnSorredArray(arr);
        int tempIndex = jump(arr, jumpSize, element);

        if(tempIndex > -1){
            int elementIndex = doLinearSearch(arr, tempIndex, jumpSize, element);
            if(elementIndex > -1){
                System.out.println("Element index in sorted array: "+elementIndex);
            }else{
                System.out.println("Element not found!");
            }
        }else{
            System.out.println("Element not found!");
        }

    }

    static int[] returnSorredArray(int[] arr){
        for(int i = 0; i < arr.length - 1; i++){
            for(int j = 0; j < arr.length-i-1; j++){
                if(arr[j+1]<arr[j]){
                    //swap
                    int temp= arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }

    static int jump(int[] arr, int jumpSize, int element){
        for(int i=0; i<arr.length; i++){
            int index = Math.min(jumpSize*i,arr.length-1);
            if(arr[index] >= element){
                return index;

            }
        }
        return -1;
    }

    static int doLinearSearch(int[] arr, int tempIndex, int jumpSize, int element){
        for(int i = tempIndex; i > tempIndex - jumpSize; i--){
            if(arr[i] == element){
                return i;
            }
        }
        return -1;
    }
}
