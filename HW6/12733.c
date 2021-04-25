#include <stdio.h>
#include <string.h>
#define MOD 1000000007

char str[10000005];
char sub[10000005];

void substring(int left, long long int len);

int main(){
  int t;
  int x;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &x);
    scanf("%s", &str);
    long long int tlen = strlen(str);
    long long int slen = strlen(str);

    for(int j = 0; j < x && j < slen; j++){
      int left = str[j] - '0'; 

      if(left > 1 && slen <= x){

        substring(j, tlen - j - 1);
        long long int sublen = strlen(sub);
        for (int k = 0; k < left - 1; k++)
        {
          strcat(str, sub);
          slen += sublen;
        }
      }
      tlen = ((j + 1) % MOD + left * (tlen - (j + 1)) % MOD + MOD) % MOD;
    }
    printf("%lld\n", tlen);
  }
}

void substring(int j, long long int len) {
  for(int i = 0; i + j < len; i++){
    sub[i] = str[i + j + 1];
  }
}