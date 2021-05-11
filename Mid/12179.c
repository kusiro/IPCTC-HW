#include <stdio.h>

int n, count, q[15];
void place(int row);
int valid(int r, int c);

int main(void)
{
  scanf("%d", &n);
  count = 0;
  place(0);
  printf("%d\n", count);
}

int valid(int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    if (q[i] == c)
      return 0;
    if (r - i == c - q[i] || r - i == q[i] - c)
      return 0;
  }
  return 1;
}

void placeNext(int row, int col){
  if (row >= n || col >=n)
  {
    count++;
    return;
  }
  else
  {
    if (valid(row, col))
    {
      q[row] = col;
      placeNext(row + 1, col);
      placeNext(row, col + 1);
    }
  }
}

void place(int row)
{
  if (row >= n)
  {
    count++;
    return;
  }
  else
  {
    for (int i = 0; i < n ; i++)
    {
      if (valid(row, i))
      {
        q[row] = i;
        place(row + 1);
      }
    }
  }
}