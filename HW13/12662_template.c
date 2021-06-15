#include <iostream>
#include <algorithm>
using namespace std;

int a[300005];
long long int dp[300005];
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n, p, k;
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
      if (i < k - 1)
        dp[i] = dp[i - 1] + a[i];
      else
        dp[i] = a[i] + dp[i - k];
    }
    int now = 0;
    for (int i = 0; i < n; i++)
    {
      if (dp[i] <= p)
        now = i + 1;
      else
        continue;
    }
    printf("%d\n", now);
  }
}