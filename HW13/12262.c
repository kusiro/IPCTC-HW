#include <stdio.h>
#include <stdlib.h>

int products[300005];
long long int dp[300005];

int compare(const void *a, const void *b){
  const int *nA = a;
  const int *nB = b;
  return *nA - *nB;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n, p, k;
    long long int temp;
    scanf("%d %d %d", &n, &p, &k);
    for(int i = 0; i < n; i++){
      scanf("%d", &products[i]);
    }

    qsort(products, n, sizeof(int), compare);

    for(int i = 0; i < n; i++){
      if (i < k - 1)
        dp[i] = dp[i - 1] + products[i];
      else
        dp[i] = products[i] + dp[i - k];

      // long long int cash = p;
      // temp = 0;
      // if(products[i] <= cash){
      //   if(i + k <= n){
      //     temp += k;
      //     cash -= products[i];
      //     for (long long int j = i + k; j < n; j++)
      //     {
      //       if (cash >= products[j])
      //       {
      //         temp++;
      //         cash -= products[j];
      //       }
      //     }
      //   } else {
      //     temp++;
      //     cash -= products[i];
      //     for (long long int j = i + 1; j < n; j++)
      //     {
      //       if (cash >= products[j])
      //       {
      //         temp++;
      //         cash -= products[j];
      //       }
      //     }
      //   }
      // }
      // if(temp > count)
      //   count = temp;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp[i] <= p)
        count = i + 1;
    }
    printf("%d\n", count);
  }
}
