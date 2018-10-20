#include <stdio.h>

double harmonicMean(int firstNum, int secondNum){
  return ((double)2*firstNum*secondNum / (double)(firstNum + secondNum));
}

int main(int argc, char const *argv[]) {
  double result=harmonicMean(31,69);
  printf("Harmonic mean of %d and %d is:%lf\n",31,69, result);
  return 0;
}
