#include <stdio.h>

int main(){
  long long int a;
  scanf("%lld", &a);
  printf("%lld %lld\n", a * 8 + a, a * 8);
}