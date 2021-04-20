#include <stdio.h>

int main() {
  int input;
  int a[100];
  int i = 0, carry = 0, isCarry = 1;

  scanf("%d", &input);
  if(input == 0) {
    printf("1 0");
  }
  else {
    for (i = 0; input > 0; i++)
    {
      a[i] = input % 2;
      input /= 2;
    }
    for (int j = 0; j < 10; j++)
    {
      if(j == i) {
        if(isCarry == 1)
          a[j] = 1;
        else  
          a[j] = 0;
      }
      else {
        if (a[j] == 1)
        {
          if (isCarry == 1)
          {
            carry++;
            a[j] = 0;
          }
          else
            isCarry = 0;
        }
        else
        {
          if (isCarry == 1)
          {
            a[j] = 1;
            isCarry = 0;
          }
          else
            isCarry = 0;
        }
      }
    }
    if(a[i] == 1)
      printf("%d", a[i]);
    for (int j = i - 1; j >= 0; j--)
    {
      printf("%d", a[j]);
    }
    printf(" %d", carry);
  }
    

}