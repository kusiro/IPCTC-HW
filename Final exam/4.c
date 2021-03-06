#include <stdio.h>

long long int a[200005];
int n, m;

long long int Count(int x){
  long long int ans = 0;
  int round = 0;
  for(int i = 0; i < n;i++){
    if(a[i] - round <= 0)
      break;
    if(i % x == x - 1) {
      ans += a[i] - round;
      round++;
    }
    else
      ans += a[i] - round;
  }
  return ans;
}

int compare(const void *a, const void *b){
  int c = *(int *)a;
  int d = *(int *)b;
  return d - c;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    qsort(a, n, sizeof(long long int), compare);
    long long int day = -1;
    int R = n + 1;
    int L = 1;
    while(R > L){
      int mid = (L + R) / 2;
      if(Count(mid) > m) {
        R = mid;
        day = mid;
      }
      else
        L = mid + 1;
    }
    printf("%lld\n", day);
  }
}