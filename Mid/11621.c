#include <stdio.h>
#include <string.h>

char s[2010];
char substring[2010];

void getsub(int start, int len){
  int j = 0;
  for(int i = start; i > start - len; i--){
    substring[j] = s[i];
    j++;
  }
}

int main(){
  while(scanf("%s", &s) != EOF)
  {
    int s_len = strlen(s);
    long long int count = 0;
    for(int i = 0; i < s_len - 1; i++)
    {
      for (int j = i + 1; j < s_len; j++)
      {
        if(s[i] == s[j]){

          if((j - i + 1) % 2 == 0) {
            getsub(j, (j - i + 1) / 2);
            if (strncmp(&s[i], substring, (j - i + 1) / 2) == 0){
              count++;
              // printf("%d %d\n", i, j);
            }
          } else {
            getsub(j, (j - i + 1) / 2);
            if (strncmp(&s[i], substring, (j - i + 1) / 2) == 0){
              count++;
              // printf("%d %d\n", i, j);
            }
          }
        }
      }
    }
    printf("%lld\n", count);
  }
}