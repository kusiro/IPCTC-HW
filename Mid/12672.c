#include <stdio.h>

int main() {
  long long int A, B, C;
  scanf("%lld %lld %lld", &A, &B, &C);
  long long int a = (A + B + C) / 2 - B;
  long long int b = (A + B + C) / 2 - C;
  long long int c = (A + B + C) / 2 - A;
  printf("%lld %lld %lld\n", a, b, c);
}