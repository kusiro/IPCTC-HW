#include <stdio.h>

char map[1005][1005];
int visited[1005][1005];
int count;
int a, b;

void dfs(int x, int y, int first){
  if(visited[x][y] == 1){
    return;
  }
  if(map[x][y] == '.'){
    visited[x][y] = 1;
    return;
  }
  if(map[x][y] == '~'){
    visited[x][y] = 1;
    if(first){
      count++;
    }
    if(x < a - 1)
      dfs(x + 1, y, 0);
    if(x > 0)
      dfs(x - 1, y, 0);
    if(y < b - 1)
      dfs(x, y + 1, 0);
    if(y > 0)
      dfs(x, y - 1, 0);
  }
  return;
}

int main(){
  scanf("%d%d", &a, &b);
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      char k;
      scanf("%c", &k);
      if (k == '\n')
        j--;
      else
        map[i][j] = k;
    }
  }
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      dfs(i, j, 1);
    }
  }
  printf("%d\n", count);
}