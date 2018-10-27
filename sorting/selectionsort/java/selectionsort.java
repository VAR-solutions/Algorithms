import java.util.*;
class Select
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        int size;
        int temp;
        System.out.println("Enter the size of the array"); 
        size=sc.nextInt();
        int arr[]=new int[size];
        System.out.println("Enter array elements");
        for(int i=0;i<size;i++)
        {
            arr[i]=sc.nextInt();
            
        }
        for(int k=0;k<size;k++)
        {
            for(int j=k+1;j<size;j++)
            {
                if(arr[k]>arr[j])
                {
                    temp=arr[j];
                    arr[j]=arr[k];
                    arr[k]=temp;
                }
            }
        }
        System.out.println("Sorted array \n");
        for(int g=0;g<size;g++)
        {
            System.out.println(arr[g]);
        }
    }
}
