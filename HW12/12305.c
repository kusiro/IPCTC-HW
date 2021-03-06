#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int index;
  long long int license_number;
  int admin_level;
} student;

int compare(const void *A, const void *B)
{
  student a = *(student *)A;
  student b = *(student *)B;
  if (a.admin_level != b.admin_level)
    return a.admin_level - b.admin_level;
  else if (a.license_number != b.license_number)
    return a.license_number - b.license_number;
  else
    return a.index - b.index;
}

student ans[100005];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    ans[i].index = i + 1;
    scanf("%d", &ans[i].admin_level);
    scanf("%lld", &ans[i].license_number);
  }

  qsort(ans, n, sizeof(student), compare);

  for (int i = 0; i < n; i++)
  {
    printf("%d", ans[i].index);
    if (i != n - 1)
      printf(" ");
    else
      printf("\n");
  }
}