#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ans[1002][1002];
char *num[1002];

int compare(const void *A, const void *B)
{
  return strlen(*(char **)A) - strlen(*(char **)B);
}
int main()
{
  int n;
  int flag = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", ans[i]);
    num[i] = ans[i];
  }
  qsort(num, n, sizeof(char *), compare);
  for (int i = 0; i < n - 1; i++)
  {
    if (strstr(num[i + 1], num[i]) == NULL)
    {
      flag = 0;
      break;
    }
  }
  if (flag)
  {
    printf("YES\n");
    for (int i = 0; i < n; i++)
    {
      printf("%s\n", num[i]);
    }
  }
  else
    printf("NO\n");
}