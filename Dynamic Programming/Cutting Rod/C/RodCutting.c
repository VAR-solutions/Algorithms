#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

const int INF = 100000;
int r[5+1];

void init_r() {
  int i;
  r[0] = 0;
  for(i=1; i<=5; i++) {
    r[i] = -1*INF;
  }
}

int top_down_rod_cutting(int c[], int n) {
  if (r[n] >= 0) {
    return r[n];
  }

  int maximum_revenue = -1*INF;
  int i;

  for(i=1; i<=n; i++) {
    maximum_revenue = MAX(maximum_revenue, c[i] + top_down_rod_cutting(c, n-i));
  }

  r[n] = maximum_revenue;
  return r[n];
}

int main() {
  init_r();
  // array starting from 1, element at index 0 is fake
  int c[] = {0, 10, 24, 30, 40, 45};
  printf("%d\n", top_down_rod_cutting(c, 5));
  return 0;
}
