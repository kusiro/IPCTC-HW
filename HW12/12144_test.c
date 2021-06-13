#include <stdio.h>
#include<stdlib.h>
typedef struct {    
    int hp, atk, x, y;
}role;
typedef struct{   
    role m[1001];
}mon;
role *now;
int k;
int tox[] = {1, -1, 0, 0};
int toy[] = {0, 0, 1, -1};
int view[6][6];

int encounter(role hero, mon mstr);
int attack(int id, role * obj, role *mstr);
int can_go(int x, int y);

int dfs(int x, int y, role hero, mon mstr)
{
  hero.x = x;
  hero.y = y;

  if (encounter(hero, mstr) > 0)
  {
    if (!attack(encounter(hero, mstr), &hero, mstr.m))
      return 0;
  }
  if (x == 5 && y == 5)
    return 1;
  for (int i = 0; i < 4; i++)
  {
    if (can_go(x + tox[i], y + toy[i]))
    {
      view[x + tox[i]][y + toy[i]] = 1;
      if (dfs(x + tox[i], y + toy[i], hero, mstr))
        return 1;
      view[x + tox[i]][y + toy[i]] = 0;
    }
  }
  return 0;
}
int main(void) {
  role hero;
  mon mstr;
  scanf("%d%d", &hero.hp, &hero.atk);
  scanf("%d", &k);
  for(int i = 1; i <= k; i++)
    scanf("%d%d%d%d", &mstr.m[i].hp, &mstr.m[i].atk, &mstr.m[i].x, &mstr.m[i].y);
  if(dfs(1, 1, hero, mstr))
    printf("HEIR OF FIRE DESTROYED\n");
  else
    printf("YOU DIED\n");
  return 0;
}

int can_go(int x, int y)
{
  if (x > 5 || x < 1 || y > 5 || y < 1 || view[x][y] == 1)
    return 0;
  else
    return 1;
}

int encounter(role hero, mon mstr)
{
  for(int i =1; i <= k; i++)
  {
    if(hero.x == mstr.m[i].x && hero.y == mstr.m[i].y){
      now = &mstr.m[i];
      return i;
    }
      
  }
  return 0;
}

int attack(int id, role *hero, role *mstr)
{
  // int round = (mstr + id)->hp / (*hero).atk;
  // if ((mstr + id)->hp % (*hero).atk == 0){
  //   round--;
  // }
  // (*hero).hp -= ((mstr + id)->atk * round);
  // return ((*hero).hp);
  while(hero->atk--)
  {
    (*now).hp--;
    if ((*now).hp <= 0)
      return 1;
    if ((*now).atk)
    {
      (*now).atk--;
      hero->hp--;
      if(hero->hp <= 0)
        return 0;
    }
  }
  if ((hero->hp) > ((*now).atk))
    return 1;
  else
    return 0;
}