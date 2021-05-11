#include <stdio.h>
int gcd(int m, int n)
{
  int t = 1;
  while (t != 0)
  {
    t = m % n;
    m = n;
    n = t;
  }
  return m;
}

int gcd_recurcive(int m, int n){
   if(m % n != 0){
     gcd_recurcive(n, m%n);
   } else {
     return n;
   }
}

int main() {
  int n;
  int a[1005];
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for(int i = 1; i < n; i++){
    for(int j = i + 1; j <= n; j++){
      int current = gcd_recurcive(a[i], a[j]);
      if(ans < current){
        ans = current;
      }
    }
  }
  printf("%d\n", ans);
}