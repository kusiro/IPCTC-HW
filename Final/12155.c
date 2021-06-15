#include <stdio.h>
#include <stdlib.h>

int blackHole = 0;
int remain = 0;
int n, r;

typedef struct {
  int x;
  int y;
}position;

position catToast[1005]; 
int visited[1005];

void dfs(int now){
  int check = 0;
  visited[now] = 1;
  for(int i = 0; i < n; i++){
    int distance = (catToast[now].x - catToast[i].x) * (catToast[now].x - catToast[i].x) + (catToast[now].y - catToast[i].y) * (catToast[now].y - catToast[i].y);
    if(distance <= r * r && i != now)
    {
      check++;
      if(visited[i] != 1){
        dfs(i);
      }
    }
  }
  if (check == 0)
  {
    remain++;
  }
}

int main(){
  scanf("%d %d", &n, &r);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &catToast[i].x, &catToast[i].y);
  }
  for(int i = 0; i < n; i++){
    if(visited[i] == 0){
      blackHole++;
      dfs(i);
    }
  }
  printf("%d %d\n", remain, blackHole - remain);
}