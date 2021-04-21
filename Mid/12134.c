#include <stdio.h>

int main(){
  int leftInt, leftFloat, rightInt, rightFloat;
  int temp;
  scanf("%d.%d %d.%d", &leftInt, &leftFloat, &rightInt, &rightFloat);
  temp = (leftInt * 100 + leftFloat) * (rightInt * 100 + rightFloat);
  printf("%d.%d%d%d%d\n", temp / 10000, temp % 10000 / 1000, temp % 1000 / 100, temp % 100 / 10, temp % 10);
}