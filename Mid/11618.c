#include <stdio.h>

long long gcd(long long int a, long long int b);
long long lcm(long long int a, long long int b);

int main(){
  int t;
  long long int n, x1, x2, x3;
  scanf("%d", &t);
  while(t--){
    scanf("%lld %lld %lld %lld", &n, &x1, &x2, &x3);
    x1 = gcd(n, x1);
    x2 = gcd(n, x2);
    x3 = gcd(n, x3);
    printf("%lld\n", n / lcm(lcm(x1, x2), x3));
  }

}

long long gcd(long long int a, long long int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long int a, long long int b){
  return (a / gcd(a, b)) * b;
}