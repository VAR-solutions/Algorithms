int search(List<int> arr, int item) {
  int len = arr.length;
  for(int i=0;i<len;i++)
    if(arr[i] == item)
      return i;
  return -1;
} 

void main() {
  List<int> arr = [1,6,3,8,4,9];
  int pos = search(arr,8);
  if(pos==-1)
    print('Element not found');
  else
    print(pos);
}
