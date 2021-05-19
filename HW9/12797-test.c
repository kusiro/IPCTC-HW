#include <stdio.h>

long long num[200001] = {0};
long long p[200001] = {0};
long long prefix[200001] = {0};

int main(void)
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    for(int i = 0; i < 200001; i++){ // Initial array
      num[i] = 0;
      p[i] = 0;
      prefix[i] = 0;
    }
    int x, z, i;
    for (x = A; x <= B; x++) //在 x+B 處+1,在 x+C+1 處-1
    {
      num[x + B]++;
      num[x + C + 1]--;
    }

    for (i = 1; i <= 200000; i++) //p 把 num 統計的結果累加起來, 得出 x+y 值為i 會出現幾次
    {
      p[i] = p[i - 1] + num[i];
    }
    for (i = 1; i <= 200000; i++) //prefix 把 p 統計的結果累加起來
    {
      prefix[i] = prefix[i - 1] + p[i];
    }
    //枚舉z, 求出答案
    long long ans = 0;
    for (z = C; z <= D; z++)
    {
      ans = ans + (prefix[200000] - prefix[z]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}