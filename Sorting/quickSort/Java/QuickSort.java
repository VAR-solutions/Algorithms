//Welcome to Jus10's Sorting Algorithms, featuring QuickSort

import java.util.Random;
import java.util.*;
	//O(nlogn)
public class QuickSort{
	static int comparison=0;
	static int pass=0;
	public static void main(String[] args){
		int [] number= {25,6,3,2,1,8,9,20,19,0};
		
		quickSort(number,0,number.length-1);
		System.out.println("Number of comparisons:"+comparison);
		System.out.println("Number of passes:"+pass);
		System.out.println("SORTED: "+Arrays.toString(number));
	}
	static void quickSort(int[] a,int x,int y){
		if(a.length==0)
			return ;
		if(x>=y)
			return;
		Random rand=new Random();
		int range=y-x+1;
		int pivot=a[rand.nextInt(range)+x];
		//int pivot=a[6];
		
		//System.out.println(pivot);
		int low=x; 
		int high=y;
		System.out.println(Arrays.toString(a));
		while(low<=high){
			while(a[low]<pivot){
				comparison++;
				low++;
			}
			
			while(a[high]>pivot){
				comparison++;
				high--;
			}
			if(low<=high){
				Swap(a,low,high);
				low++;
				high--;
			}
			//System.out.println(Arrays.toString(a));
		}	
		pass++;
		if(x<high){
			//System.out.println("x:"+x+" high:"+high);
			quickSort(a,x,high);
		}
		//these if statements exist para hindi magcause ng ArrayIndexOutOfBounds and Infinite loops
		if(y>low){
			//System.out.println(y+" "+low);
			quickSort(a,low,y);
		}			
	}
	
	//haba no? tldr nyo nalang, panoorin nyo na to https://www.youtube.com/watch?v=aQiWF4E8flQ
	public static int[] Swap(int A[],int p,int q){
		int temp=0;
		
		temp=A[p];
		A[p]=A[q];
		A[q]=temp;
		
		return A;
					
	}
	
	
	//improve by finding the mean of the array
	//search pivot through linear search
	
}