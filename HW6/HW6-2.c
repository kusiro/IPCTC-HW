#include <stdio.h>

int a[25];
int ans = 0;
int findAns(int current,int n, int k, int tempAdd){
  if(current <= n){
    if (tempAdd == k)
    {
      ans++;
      return;
    }
    else if (tempAdd < k)
    {
      findAns(current+1, n, k, tempAdd + a[current]);
      findAns(current+1, n, k, tempAdd);
    }
    else
      return;
  }
  else {
    return;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  findAns(0, n, k, 0);
  printf("%d\n", ans);
}