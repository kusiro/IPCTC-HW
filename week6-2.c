#include <stdio.h>

int main(){
  long long int query, a, b, c;
  scanf("%lld", &query);
  for(int i = 0; i < query; i++){
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a >= b && a >= c){
      if(a >= b + c){
        printf("%lld\n", b + c);
      } else {
        printf("%lld\n", (b + c - a)/2 + a);
      }
    } else if(b >=a && b >=c) {
      if(b >= a + c){
        printf("%lld\n", a + c);
      } else {
        printf("%lld\n", (a + c - b)/2 + b);
      }
    } else {
      if(c >= b + a){
        printf("%lld\n", b + a);
      } else {
        printf("%lld\n", (b + a - c)/2 + c);
      }
    }
  }
}