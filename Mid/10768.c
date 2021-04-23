#include <stdio.h>

int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if(b % a == 0 && c % b == 0){
    if(b / a == c / b){
      printf("%d %d", a / (b / a), c * (b / a));
    }
  }
  if(b - a == c - b){
    printf("%d %d", a - (b - a), c + (b - a));
  }
}