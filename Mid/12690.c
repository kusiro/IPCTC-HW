#include <stdio.h>
char a[100005];
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%c", &a[i]);
  }
  printf("%d\n", n + 1);
}