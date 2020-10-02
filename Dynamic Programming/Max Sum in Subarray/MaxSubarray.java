package algorithms;

public class MaxSubarray {
	
	public int maxsub(int[] a){
		int max = a[0];
		int submax = 0;
		int curr_max = a[0];
		int size = a.length;
		for(int i=1;i<size;i++){
			if( a[i] > curr_max+a[i]){
				curr_max = a[i];
			}
			else{
				curr_max += a[i];
			}
			
			if(max < curr_max){
				max = curr_max;
			}
			
		}
		seq(a);
		return max;
	}
	public int seq(int[] ar){
		
		merge(ar,0,ar.length/2,ar.length - 1);
		int sum = ar[ar.length-1];
		for(int i =ar.length -1; i>=0;i--){
			if(sum < sum + ar[i]){
				sum +=ar[i];
				
			}
		}
		//System.out.println(sum);
		return 0;
	}
	void merge(int arr[], int l, int m, int r) 
    { 
        // Find sizes of two subarrays to be merged 
        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        /* Create temp arrays */
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        /*Copy data to temp arrays*/
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
  
        /* Merge the temp arrays */
  
        // Initial indexes of first and second subarrays 
        int i = 0, j = 0; 
  
        // Initial index of merged subarry array 
        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        /* Copy remaining elements of L[] if any */
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        /* Copy remaining elements of R[] if any */
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
  
    // Main function that sorts arr[l..r] using 
    // merge() 
    void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            // Find the middle point 
            int m = (l+r)/2; 
  
            // Sort first and second halves 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            // Merge the sorted halves 
            merge(arr, l, m, r); 
        } 
    } 

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] ar = {-2,-3,-1,-4,-6,5,7};
		MaxSubarray ms = new MaxSubarray();
		int max = ms.maxsub(ar);
		System.out.println(max);

	}

}
