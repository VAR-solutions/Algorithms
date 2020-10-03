/*
Search a sorted array by repeatedly dividing the search interval in half.
Begin with an interval covering the whole array. If the value of the search
key is less than the item in the middle of the interval,
narrow the interval to the lower half. Otherwise narrow it to the upper half.
Repeatedly check until the value is found or the interval is empty.
*/
static int binarySearch(int[] arr, int e, int min, int max) 
{ 
    if (max >= min)
    {
        int mid = (min + max) / 2;
        
        if (arr[mid] > e) 
        {
            return binarySearch(arr, e, min, mid - 1); 
        }
        else if (arr[mid] < e) 
        {
            return binarySearch(arr, e, mid + 1, max); 
        }
        else
        {
            return mid;
        }
    }        
    return -1;
} 