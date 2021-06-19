#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y, atk, hp;
}role;

typedef struct 
{
  role m[100];
}Mons;

int k;
int visited[6][6];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int dfs(int x, int y, Mons monster, role hero);
int encounter(Mons monster, role hero);
int battle(role *monster, role hero);
int canGo(int x, int y);

int main(){
  role hero;
  Mons monster; 
  scanf("%d %d %d", &hero.hp, &hero.atk, &k);
  for(int i = 1; i <= k; i++){
    scanf("%d %d %d %d", &monster.m[i].hp, &monster.m[i].atk, &monster.m[i].x, &monster.m[i].y);
  }

  if(dfs(1, 1, monster, hero))
    printf("HEIR OF FIRE DESTROYED\n");
  else
    printf("YOU DIED\n");
}

int dfs(int x, int y, Mons monster, role hero)
{
  hero.x = x;
  hero.y = y;
  int monsNum;
  if (encounter(monster, hero) > 0) {
    monsNum = encounter(monster, hero);
    if(!battle(&monster.m[monsNum], hero)) {
      return 0;
    }
  }
  if(x == 5 && y == 5){
    return 1;
  }
  for(int i = 0; i < 4; i++){
    if(canGo(x + moveX[i], y + moveY[i])){
      visited[x + moveX[i]][y + moveY[i]] = 1;
      if(dfs(x + moveX[i], y + moveY[i], monster, hero))
        return 1;
      visited[x + moveX[i]][y + moveY[i]] = 0;
    }
  }
  return 0;
}

int encounter(Mons monster, role hero) {
  for(int i = 1; i <= k; i++){
    if (hero.x == monster.m[i].x && hero.y == monster.m[i].y){
      return i;
    }
  }
  return 0;
}

int battle(role *monster, role hero) {
  hero.hp -= (((monster->hp / hero.atk) + (monster->hp % hero.atk) - 1) * monster->atk);
  if (hero.atk <= 0 && monster->hp > 0) {
    return 0;
  } else if (hero.hp <= 0) {
    return 0;
  }
  else {
    return hero.hp - (((monster->hp / hero.atk) + (monster->hp % hero.atk) - 1) * monster->atk);
  }
}

int canGo(int x, int y){
  if(x < 1 || x > 5 || y < 1 || y > 5 || visited[x][y] == 1)
    return 0;
  else
    return 1;
}