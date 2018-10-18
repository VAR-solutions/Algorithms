package geeksforgeeks;
import java.util.Scanner;
import java.util.Arrays;


public class KthLargest {
    public void KthString(int a[],int n,int k)
    {
        int arr[];
        
        String s = "";
        for(int i=0;i<k-1;i++)
            s=s+"-1 ";
        for(int j=k;j<=n;j++)
        {
            arr = Arrays.copyOf(a, j);
            Arrays.sort(arr);
            s=s+" ";
            s=s+arr[j-k];
        } 
        System.out.println(s);
        
    }
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Input the number of elements");
        int n= sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        KthLargest ob=new KthLargest();
        System.out.println("Input the value of k");
        int k= sc.nextInt();
        ob.KthString(arr, n, k);
        
    }
    
}
