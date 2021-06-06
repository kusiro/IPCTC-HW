#include <stdio.h>
int main(){
  int n, k;
  long long int now = 0;
  long long int point = 0;
  long long int next;
  int ans = 0;
  int flag = 0;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){
    scanf("%lld", &next);
    if(next - now > k) {
      flag = 1;
      break;
    } else if(next - point <= k) {
      now = next;
    } else {
      point = now;
      now = next;
      ans++;
    }
  }
  if(flag == 0)
    printf("%d\n", ans);
  else
    printf("Legand fall!\n");
}