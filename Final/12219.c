#include <stdlib.h>
#include <stdio.h>

long long int fastPower(long long int x, long long int y, long long int m){
  if(y == 1){
    return x % m;
  } else if(y == 0)
    return 1;

  long long int product = fastPower(x, y / 2, m);
  product = (product * product) % m;
  if(y % 2 == 1){
    product = (product * x) % m;
  }
  return product;
}

int main() {
  long long x, y, m;
  scanf("%lld%lld%lld", &x, &y, &m);
  if(m == 0)
    printf("0\n");
  else
    printf("%lld\n", fastPower(x, y, m));
}