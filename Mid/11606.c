#include <stdio.h>
#include <math.h>

int main(){
  int n, T, R, count, current, currentCount;
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &T, &R);
    current, currentCount = 0;
    for (int i = T; i <= R; i++)
    {
      count = 0;

      for (int j = 1; j < sqrt(i); j++)
      {
        if (i % j == 0)
          count++;
      }
      count *= 2;
      if (sqrt(i) == (int)sqrt(i))
        count++;
      if (count > currentCount)
      {
        currentCount = count;
        current = i;
      }
    }
    printf("%d\n", current);
  }
}