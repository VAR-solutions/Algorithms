void bubbleSort(List list) 
{
  if (list == null || list.length == 0) 
    return;

  int num = list.length;
  int i, step;
  for (step = 0; step < num; step++) {
    for ( i = 0; i < num - step - 1; i++) {
      if (list[i] > list[i + 1]) {
        swap(list, i);
      }
    }
  }
}

void swap(List list, int i) {
  int temp = list[i];
  list[i] = list[i+1];
  list[i+1] = temp;
}