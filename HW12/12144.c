#include <stdio.h>

typedef struct
{
  int HP, ATK, x, y;
} Obj;

typedef struct
{
  Obj m[50];
} monster;

int n;
int visited[6][6];
int tox[] = {1, -1, 0, 0};
int toy[] = {0, 0, 1, -1};
monster mon;
Obj *now;
int encounter(Obj hero, monster mon)
{
  for (int i = 0; i < n; i++)
  {
    if (hero.x == mon.m[i].x && hero.y == mon.m[i].y)
    {
      now = &mon.m[i];
      return 1;
    }
  }
  return 0;
}
int battle(Obj *hero, Obj *m)
{
  printf("%d\n", (*m).HP);
  int round = (*m).HP / (*hero).ATK;
  if ((*m).HP % (*hero).ATK == 0)
    round--;
  (*hero).HP -= (*m).ATK * round;
  return (*hero).HP;
}

int can_go(int x, int y)
{
  if (x > 5 || x <= 0 || y > 5 || y <= 0)
    return 0;
  else
    return 1;
}

int dfs(int x, int y, Obj hero, monster mon)
{
  hero.x = x;
  hero.y = y;
  if (visited[x][y] == 1)
    return 0;
  if (encounter(hero, mon))
  {
    if (!battle(&hero, now))
    {
      return 0;
    }
  }
  if (x == 5 && y == 5)
    return 1;
  for (int i = 0; i < 4; i++)
  {
    if (can_go(x + tox[i], y + toy[i]))
    {
      visited[x + tox[i]][y + toy[i]] = 1;
      if (dfs(x + tox[i], y + toy[i], hero, mon))
        return 1;
      visited[x + tox[i]][y + toy[i]] = 0;
    }
  }
  return 0;
}

int main()
{
  Obj hero;
  scanf("%d%d%d", &hero.HP, &hero.ATK, &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d%d%d", &mon.m[i].HP, &mon.m[i].ATK, &mon.m[i].x, &mon.m[i].y);
  if (dfs(1, 1, hero, mon))
    printf("HEIR OF FIRE DESTROYED\n");
  else
    printf("YOU DIED\n");

  for (int i = 0; i < n; i++)
    printf("%d %d %d %d\n", mon.m[i].HP, mon.m[i].ATK, mon.m[i].x, mon.m[i].y);
}