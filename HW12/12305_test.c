#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int index;
  int admin_level;
  long long int license_number;
} student;

int compare(const void *A, const void *B){
  student a = *(student *)A;
  student b = *(student *)B;
  if(a.admin_level != b.admin_level)
    return a.admin_level - b.admin_level;
  else if(a.license_number != b.license_number)
    return a.license_number - b.license_number;
  else if (a.index != b.index)
    return a.index - b.index;
}

student ans[100005];

int main(){
  long long int n;
  scanf("%lld", &n);
  for(long long int i = 0; i < n; i++){
    ans[i].index = i + 1;
    scanf("%d %lld", &ans[i].admin_level, &ans[i].license_number);
  }

  qsort(ans, n, sizeof(student), compare);

  for(long long int i = 0; i < n; i++){
    (i != n - 1) ? (printf("%d ", ans[i].index)) : printf("%d\n", ans[i].index);
  }
}