#include <stdio.h>

int main(){

  // for (int i = 1; i <= 50000; i++)
  // {
  //   for (int j = 1; j <= 50000; j++)
  //   {
  //     if (i + j < d)
  //     {
  //       if (i + j > c)
  //       {
  //         count = i + j - c + count;
  //       }
  //     }
  //     else if (i + j > d)
  //     {
  //       count += (d - c + 1);
  //     }
  //     else
  //     {
  //       count += (d - c);
  //     }
  //   }
  // }

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
            count = i + j - c + count;
          }
        }
        else if (i + j > d)
        {
          count += (d - c + 1);
        }
        else
        {
          count += (d - c);
        }
      }
    }
    printf("%lld\n", count);
  }
}