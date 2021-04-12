#include <stdio.h>

long long prifix[1000005];
int main() {
  int t;
  long long int a, b, current;
  int ans;
  prifix[0] = 0;
  for(long long j = 1; j <= 1000000; j++){
    ans = 0;
    current = j;
    while(current){
      if(current % 10 == 1) ans++;
      current /= 10;
    }
    prifix[j] = ans + prifix[j - 1];
  }
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    scanf("%lld %lld", &a, &b);
    
    printf("%d\n", prifix[b] - prifix[a-1]);
  }
}