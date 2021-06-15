#include <stdio.h>

long long int a[2000000];

int main(){
  int n, q, k;
  long long int max;
  scanf("%d %d %d", &n, &k, &q);
  for(int i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
  }
  max = a[n];
  while(q--){
    int L = 1;
    int R = n;
    int mid;
    long long int f;
    long long int ans;
    scanf("%lld", &f);
    if(f > max){
      printf("gan ni nya sai bau\n");
    } else {
      if( n == 1)
        printf("%d\n", 1);
      else {
        while (1)
        {
          mid = (L + R) / 2;
          if(L == mid){
            if(L == k){
              ans = R;
              break;
            } else if(L > k) {
              ans = R;
              break;
            } else {
              if (f <= a[L])
                ans = L;
              else
                ans = R;
              break;
            }
          } else {
            if (f > a[mid])
            {
              L = mid;
            }
            else if (f < a[mid])
            {
              R = mid;
            }
            else
            {
              ans = mid;
              for (int i = mid; i > 0 && a[i] == a[mid]; i--)
              {
                ans = i;
              }
              break;
            }
          }
        }
        if (ans > k)
          printf("%d\n", ans - k);
        else
          printf("%d\n", ans + (n - k));
      }
    }
    

  }
}