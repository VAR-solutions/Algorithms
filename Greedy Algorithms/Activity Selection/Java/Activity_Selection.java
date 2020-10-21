import java.util.*;
class A
{
	public int find(int a[],int b[],int n)
	{
		int count=1;
		for(int i=1;i<n;i++)
		{
			int key=b[i];
			int key1=a[i];
			int j=i-1;
			while(j>=0&&b[j]>key)
			{
				b[j+1]=b[j];
				a[j+1]=a[j];
				j--;
			}
			b[j+1]=key;
			a[j+1]=key1;
		}
		int i=0;
		for(int j=1;j<n;j++)
		{
			if(b[i]<=a[j])
			{
				i=j;
				count++;
				
			}
		}
		return count;
	}
}
class Activity_Selection
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no. of activities");
		int n=sc.nextInt();
		int start[]=new int[n];
		int finish[]=new int[n];
		System.out.println("Enter the start and finish time");
		for(int i=0;i<n;i++)
		{
			start[i]=sc.nextInt();
			finish[i]=sc.nextInt();
		}
		A ob=new A();
		int ans=ob.find(start,finish,n);
		System.out.println("Maximum activity can be done = "+ans);
	}
}