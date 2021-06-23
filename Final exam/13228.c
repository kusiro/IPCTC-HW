#include <stdio.h>
#include <math.h>

int main(){
  int T;
  int a, b, c, d;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d %d", &a, &b, &c, &d);

    long long int count = 0;
    for (int i = a; i <= b; i++)
    {
      for (int j = b; j <= c; j++)
      {
        if (i + j < d)
        {
          if (i + j > c)
          {
            if (i + j < c * 1.5)
              count += i + j - c;
            else {
              int addition = (int)(((i + j) - (c * 1.5)) / 1.5) + 1;
              count += i + j - (c + addition);
            }
          }
        }
        else if (i + j > d)
        {
          if(i + j < d * 1.5){
            if(i + j < c * 1.5)
              count += d - c + 1;
            else {
              int addition = (int)(d * 1.5 - (i + j)) / 1.5;
              count += addition + 1;
            }
          }
        }
        else
        {
          if (i + j < d * 1.5)
          {
            if (i + j < c * 1.5)
              count += d - c;
            else
            {
              int addition = (int)(d * 1.5 - (i + j)) / 1.5;
              count += addition;
            }
          }
        }
      }
    }
    printf("%lld\n", count);
  }
}