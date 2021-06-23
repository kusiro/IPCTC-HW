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
            if(c * 1.5 > i + j)
              count = i + j - c + count;
            else {
              for(int now = c + 1; now < i + j; now++){
                if(now * 1.5 > (i + j)){
                  count += i + j - now;
                  break;
                }
              }
            }
          }
        }
        else if (i + j > d)
        {
          if(c * 1.5 > (i + j))
            count += (d - c + 1);
          else {
            for(int now = c + 1; now <= d; now++){
              if(now * 1.5 > (i + j)){
                count += d - now + 1;
                break;
              }
            }
          }
        }
        else
        {
          if(c * 1.5 > (i + j))
            count += (d - c);
          else {
            for(int now = c + 1; now <= d; now++){
              if(now * 1.5 > (i + j)){
                count += d - now;
                break;
              }
            }
          }
        }
      }
    }
    printf("%lld\n", count);
  }
}