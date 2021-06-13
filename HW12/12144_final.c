#include <stdio.h>
#include <stdlib.h>

#define MapSize 5
#define Inf 4294967295

typedef struct monster
{
  int hp;
  int attack;
  int r;
  int c;
  int isEverPass;
} Monster;

typedef struct you
{
  int hp;
  int attack;
  int r;
  int c;
} You;

const int dirR[4] = {1, -1, 0, 0};
const int dirC[4] = {0, 0, 1, -1};

void showMap(int (*map)[MapSize])
{
  for (int i = 0; i < MapSize; i++)
  {
    for (int j = 0; j < MapSize; j++)
    {
      printf("%d\t", map[i][j]);
    }
    printf("\n");
  }
}

int fight(const You you, const Monster mon)
{
  if (you.attack <= 0 && mon.hp > 0)
  {
    return 0;
  }
  else
  {
    return you.hp - (((mon.hp / you.attack) + (mon.hp % you.attack > 0) - 1) * mon.attack);
  }
}

int dfs(Monster (*mons)[MapSize], const You you)
{
  int isAlive = 0;
  You nowYou = you;
  if (nowYou.r >= 0 && nowYou.c >= 0 && nowYou.r < MapSize && nowYou.c < MapSize)
  {
    if (!mons[nowYou.r][nowYou.c].isEverPass)
    {
      nowYou.hp = fight(nowYou, mons[nowYou.r][nowYou.c]);
      if (nowYou.hp > 0)
      {
        if (nowYou.r == 4 && nowYou.c == 4)
        {
          return 1;
        }

        mons[nowYou.r][nowYou.c].isEverPass = 1;
        for (int i = 0; i < 4; i++)
        {
          You nextY = nowYou;
          nextY.r += dirR[i];
          nextY.c += dirC[i];
          isAlive = dfs(mons, nextY);
          if (isAlive)
          {
            return 1;
          }
        }
        mons[nowYou.r][nowYou.c].isEverPass = 0;
      }
    }
  }
  return 0;
}

int main()
{
  You y;
  Monster mons[MapSize][MapSize];
  int k = 0, isAlive = 0;

  scanf("%d %d %d\n", &(y.hp), &(y.attack), &k);
  y.r = 0;
  y.c = 0;

  for (int i = 0; i < MapSize; i++)
  {
    for (int j = 0; j < MapSize; j++)
    {
      mons[i][j].hp = 0;
      mons[i][j].attack = 0;
      mons[i][j].isEverPass = 0;
    }
  }

  for (int i = 0; i < k; i++)
  {
    int hp = 0, attack = 0, r = 0, c = 0;
    scanf("%d %d %d %d\n", &hp, &attack, &r, &c);
    mons[r - 1][c - 1].hp = hp;
    mons[r - 1][c - 1].attack = attack;
    mons[r - 1][c - 1].r = r - 1;
    mons[r - 1][c - 1].c = c - 1;
  }
  
  isAlive = dfs(mons, y);

  if (isAlive)
  {
    printf("HEIR OF FIRE DESTROYED\n");
  }
  else
  {
    printf("YOU DIED\n");
  }

  return 0;
}