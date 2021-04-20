#include <stdio.h>
int main() {
  int flag;
  int input;
  scanf("%d", &input);
  if(input == 2400){
    printf("00:00 a.m.");
  } else {
    if (input >= 1200)
    {
      flag = 1;
      int key_info = 'a' * ((flag + 1) % 2) + 'p' * flag;
      printf("%d%d:%d%d %c.m.", input / 1000 - 1, input % 1000 / 100 - 2, (input % 100) / 10, input % 10, key_info);
    }
    else
    {
      flag = 0;
      int key_info = 'a' * ((flag + 1) % 2) + 'p' * flag;
      printf("%d%d:%d%d %c.m.", input / 1000, input % 1000 / 100, (input % 100) / 10, input % 10, key_info);
    }
  }

  
}