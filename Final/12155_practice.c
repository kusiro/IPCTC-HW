#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x, y;
}position;

// position catToast[2000];
// int visited[2000];
// int blackHole, remain;
// int n, r;

void dfs(int now){
  int check = 0;
  int distant;
  visited[now] = 1;
  for(int i = 0; i < now; i++){
    distant = sqrt(catToast[now].x - catToast[i].x) + sqrt(catToast[now].y - catToast[i].y);
    if(distant <= r * r && i != now){
      check++;
      if (visited[i] == 0)
        dfs(i);
    }
  }
  if(check == 0){
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
}