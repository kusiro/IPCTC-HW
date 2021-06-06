#include <stdio.h>
int main()
{
  int n, k;
  long long int p, now, next;
  p = 0;
  now = 0;
  int ans = 0;
  int flag = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &next);
    if (next - now > k)
    {
      flag = 1;
      break;
    }
    else if (next - p <= k)
      now = next;
    else
    {
      p = now;
      now = next;
      ans++;
    }
  }
  if (flag == 0)
    printf("%d\n", ans);
  else
    printf("The Legend Falls.\n");
}