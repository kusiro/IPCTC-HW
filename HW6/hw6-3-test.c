#include <stdio.h>
#include <string.h>
#define MOD 1000000007
char str[2000005];
char temp[2000005];  //temp是我的substring

void substring(int j,int s_len);

int main(void)
{
    int t,x;
    int s_len,left,temp_len;
    long long int t_len;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %s",&x,str);
        t_len=s_len=strlen(str);
        for(int j = 0; j < x && j < s_len; j++)
        {
          left = str[j] - '0';
          t_len = ((j + 1) % MOD + left * (t_len - (j + 1)) % MOD + MOD) % MOD;
          if (left > 1 && s_len <= x)
          {
            substring(j, s_len);
            temp_len = strlen(temp);
            for (int k = 0; k < left - 1 && s_len < x; k++)
            {
              strcat(str, temp);
              s_len += temp_len;
            }
            }
        }
        printf("%lld\n",t_len);
    }
    return 0;
}
void substring(int j, int s_len)
{

    for(int i=0;i+j<s_len;i++)
    {
        temp[i]=str[i+j+1];
    }

}