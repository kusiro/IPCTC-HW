#include <stdio.h>
#include <math.h>

long long num[200005] = {0};
long long p[200005] = {0};
long long prefix[200005] = {0};

int main(void)
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    for(int i = 0; i < 200004; i++){
      num[i] = 0;
      p[i] = 0;
      prefix[i] = 0;
    }

    int x, z, i;
    
    for (x = A; x <= B; x++)
    {
      num[x + B]++;
      num[x + C + 1]--;
    }

    for (i = 1; i <= 200000; i++)
    {
      p[i] = p[i - 1] + num[i];
    }
    for (i = 1; i <= 200000; i++)
    {
      prefix[i] = prefix[i - 1] + p[i];
    }
    long long ans = 0;
    for (z = C; z <= D; z++)
    {
      if ((int)(z * 1.5) == z * 1.5)
        ans += (prefix[(int)(z * 1.5) - 1] - prefix[z]);
      else
        ans += (prefix[(int)(z * 1.5)] - prefix[z]);
    }

    printf("%lld\n", ans);
  }
  return 0;
}