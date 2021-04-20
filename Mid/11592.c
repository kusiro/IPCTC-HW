#include <stdio.h>

int main() {
  int input;
  scanf("%d", &input);
  if(input >= 3){
    int last = (input - 3) % 3;
    if (last != 0)
      last--;
    printf("%d\n", (input - 3) / 3 * 2 + 3 + last);
  }
  else {
    printf("%d\n", input);
  }
}