void selectSorting(List list) {
  if (list == null || list.length == 0) return;
  int num = list.length;
  int i, steps;
  for (steps = 0; steps < num; steps++) {
    for (i = steps + 1; i < num; i++) {
      if(list[steps] > list[i]) {
        change(list, steps, i);
      }
    }
  }
}

void change(List list, int steps, int i) {
  int count = list[steps];
  list[steps] = list[i];
  list[i] = count;
}