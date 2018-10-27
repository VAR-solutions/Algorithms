import java.util.*;//importin java package for user input
public class bsearch
{
public static void main(String[] args)
{
Scanner sc=new Scanner(System.in);
int size;
System.out.println("Enter size of array owhich you wish you implement");//size of array on which you
size=sc.nextInt();
int arr[]=new int[size];
System.out.println("Enter values into the array);//input of values on which operation will take place
for(int i=0;i<size;i++)
{
arr[i]=sc.nextInt();
}
System.out.println("Enter the element to search");//element to search 
int key=sc.nextInt();
int l=size-1;
int f=0;
int mid=0;
while(f<=l)
{
mid=f+l/2;//parting array from middile so as reduce time comlexity from O(n) to O(logn) because now operation takes place only on sub arrays.
if(key==arr[mid])
{
System.out.println("Found");
break;
}
elseif(key>arr[mid])
{
f=mid+1;
}
elseif(key<arr[mid])
{
l=mid-1;
}
else
{
System.out.println("Not found");
}
}//end of while
}//end of main
}//end of class












