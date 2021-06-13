#include <stdio.h>
char ans[1005][1005];
int pass [1005][1005];
int count;
int a,b;
int dfs(int x,int y,int first){
  if(pass[x][y] == 1)
    return 0;
  if(ans[x][y] == '.'){
    pass[x][y] = 1;
    return 0;
  }
  if(ans[x][y] == '~'){
    pass[x][y] = 1;
    if(first)
      count ++;
    if(x<a-1)
      dfs(x+1,y,0);
    if(x>0)
      dfs(x-1,y,0);
    if(y<b-1)
      dfs(x,y+1,0);
    if(y>0)
      dfs(x,y-1,0);
  }
  return 0;
}
int main(){
  scanf("%d%d", &a, &b);
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      char k;
      scanf("%c", &k);
      if(k == '\n')
        j--;
      else
        ans[i][j] = k;
    }
  }
  // for(int i=0;i<a;i++){
  //   for(int j=0;j<b;j++)
  //     dfs(i,j,1);
  // }
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++)
      printf("%c", ans[i][j]);
  }
  // printf("%d\n", count);
}