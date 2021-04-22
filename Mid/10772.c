#include <stdio.h>
#include <string.h>

int main(){
  char a[5];
  int n;
  char b[10];
  scanf("%s", &a);
  scanf("%d", &n);

  int lenA = strlen(a);
  int count = 0;
  for(int i = 0; i < n; i++){
    int tempCount = 0;
    scanf("%s", &b);
    int lenB = strlen(b);
    for(int j = 0; j < lenB; j++){
      if(strncmp(&a[0], &b[j], lenA) == 0){
        tempCount++;
      }
    }
    if(tempCount > count)
      count = tempCount;
  }

  printf("%d", count);
}