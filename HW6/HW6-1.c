#include <stdio.h>
#include <string.h>
char a[100005], b[100005];
int isEq(int len, int sa, int sb) {
  if(len % 2 == 1)
    return(strncmp(a+sa, b+sb, len));
  else {
    if(isEq(len/2, sa, sb) == 0 && isEq(len/2, sa, sb) == 0)
      return 0;
    else if (isEq(len / 2, sa, sb + len / 2) == 0 && isEq(len / 2, sa + len/2, sb) == 0)
      return 0;
    else return 1;
  }
}

int main() {
  scanf("%s", &a);
  scanf("%s", &b);
  int len = strlen(a);

  if(isEq(len, 0, 0) == 0)
    printf("YES\n");
  else 
    printf("NO\n");
}