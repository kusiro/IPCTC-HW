#include <stdio.h>

typedef struct Twin
{
  int a;
  int b;
}twin;

twin x[100005];

int compare(const twin * x, const twin * y){
  return ((x->a - x->b) - (y->a - y->b));
}

int main()
{
  int n, k;
  long long int sum = 0;

  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &x[i].a);
  }
  for (int i = 0; i < n; i++){
    scanf("%d", &x[i].b);
  }
  qsort(x, n, sizeof(twin), compare);

  for(int i = 0; i < n; i++){
    if(i + 1 <= k || x[i].a - x[i].b < 0) sum += x[i].a;
    else sum += x[i].b;
  }
  printf("%lld\n", sum);
}