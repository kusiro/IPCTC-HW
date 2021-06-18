#include <stdio.h>
#include <stdlib.h>

long long int mod = 1e9 + 7;

typedef struct {
  long long int m[2][2];
}matrix;

matrix create(){
  matrix M;
  M.m[0][0] = 1;
  M.m[0][1] = 1;
  M.m[1][0] = 1;
  M.m[1][1] = 0;
  return(M);
}

matrix mul(matrix a, matrix b){
  matrix ans;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      ans.m[i][j] = 0;
      for(int k = 0; k < 2; k++){
        ans.m[i][j] += (a.m[i][k] * b.m[k][j]) % mod; 
      }
      ans.m[i][j] %= mod;
    }
  }
  return ans;
}

matrix fpw(long long int a){
  if(a == 1)
    return create();

  matrix product = fpw(a / 2);
  if(a % 2 == 0)
    return(mul(product, product));
  else
    return(mul(mul(product, product), create()));
}

int main(){
  long long int i;
  while(scanf("%lld", &i) != EOF){
    if(i > 2){
      matrix ans = fpw(i - 2);
      printf("%lld\n", (ans.m[0][0] + ans.m[0][1]) % mod);
    }
    else {
      printf("1\n");
    }
  }
}