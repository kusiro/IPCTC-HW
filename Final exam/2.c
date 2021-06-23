#include <stdio.h>
#include <math.h>

int main()
{
  int T;
  int a, b, c, d;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    long long int count = 0;
    for (int i = a; i <= b; i++)
    {
      if(i + b > d){
        count += d - c + 1;
      } else if( i + b == d) {
        count += d - c;
      } else {
        count += i + b - c;
      }
      // for (int j = b; j <= c; j++)
      // {
      //   int now = i + j;
      //   // now > z; now < z * 1.5 
      //   if (now < d)
      //   {
      //     if (now > c)
      //     {
      //       if (now < c * 1.5)
      //         count = now - c + count;
      //       else
      //       {
      //         int addition = (int)(((now) - (c * 1.5)) / 1.5) + 1;
      //         count += now - (c + addition);
      //       }
      //     }
      //   }
      //   else if (now > d)
      //   {
      //     if (now < c * 1.5)
      //       count += (d - c + 1);
      //     else
      //     {
      //       int addition = (int)(((now) - c * 1.5) / 1.5) + 1;
      //       if (c + addition < d)
      //       {
      //         count += d - (c + addition) + 1;
      //       }
      //       else
      //       {
      //         if(now < d * 1.5)
      //           count++;
      //       }
      //     }
      //   }
      //   else
      //   {
      //     if (now < c * 1.5)
      //       count += (d - c);
      //     else
      //     {
      //       int addition = (int)(((now) - c * 1.5) / 1.5) + 1;
      //       if (c + addition < d)
      //       {
      //         count += d - (c + addition);
      //       }
      //     }
      //   }
      // }
    }
    printf("%lld\n", count);
  }
}