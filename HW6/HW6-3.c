#include <stdio.h>
#include <string.h>
#define MOD 1000000007

char a[2000005];
char temp[2000005];

void substring(int j, int s_len) {
  for(int i = 0; i+j < s_len; i++){
    temp[i] = a[i + j + 1];
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int x;
    scanf("%d", &x);
    scanf("%s", a);
    int temp_len;
    long long int t_len = strlen(a);
    long long int s_len = strlen(a);


    for (int j = 0; j < x && j < s_len; j++)
    {
      int left = a[j] - '0';

      if (left > 1 && s_len <= x)
      {

        substring(j, s_len);
        temp_len = strlen(temp);
        for (int k = 0; k < left - 1 && s_len < x; k++)
        {
          strcat(a, temp);
          s_len += temp_len;
        }
      }

      t_len = ((j + 1) % MOD + left * (t_len - (j + 1)) % MOD + MOD) % MOD;
    }

    printf("%lld\n", t_len);
  }
}