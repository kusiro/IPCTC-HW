#include <stdio.h>

long long int fpw(long long x, long long y, long long m){
  if(y == 0)
    return 1 % m;
  else if (y == 1)
  {
    return x % m;
  }
  
  long long int res;
  res = fpw(x, y/2, m);
  res = ((res % m) * (res % m)) % m;
  if(y % 2 == 1) {
    res = ((res % m) * (x % m)) % m;
  }
  return res;
}

int main(){
  long long int x, y, m;
  scanf("%lld %lld %lld", &x, &y, &m);
  printf("%lld\n", fpw(x, y, m));
}