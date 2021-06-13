#include <stdio.h>

long long int mod = 1e9 + 7;
int p[3] = {1, 12, 13};

typedef struct 
{
  long long int m[3][3];
}matrix;

matrix create(){
  matrix M;
  M.m[0][0] = 1;
  M.m[0][1] = 2;
  M.m[0][2] = 1;
  M.m[1][0] = 1;
  M.m[1][1] = 0;
  M.m[1][2] = 0;
  M.m[2][0] = 0;
  M.m[2][1] = 1;
  M.m[2][2] = 0;
  return M;
}

matrix multi(matrix A, matrix B)
{
  matrix ans;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ans.m[i][j] = 0;
      for (int k = 0; k < 3; k++)
        ans.m[i][j] += (A.m[i][k] * B.m[k][j]) % mod;
      ans.m[i][j] %= mod;
    }
  }
  return ans;
}

matrix fpw(long long int x){
  if(x == 1) return create();

  matrix product = fpw(x / 2);

  if(x % 2 == 0)
    return(multi(product, product));
  else
    return multi(multi(product, product), create());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--)
  {
    long long int x;
    scanf("%lld", &x);
    if(x > 3){
      matrix ans = fpw(x - 3);
      printf("%lld\n", (ans.m[0][0] * 13 + ans.m[0][1] * 12 + ans.m[0][2] * 1) % mod);
    } else {
      printf("%d\n", p[x - 1]);
    }
  }
}