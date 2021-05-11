#include <stdio.h>

int main(){
  long long int x, y, m;
  long long int ans = 0;
  scanf("%lld %lld %lld", &x, &y, &m);
  for(int i = 0; i < y; i++){
    ans *= (x % m);
  }
}