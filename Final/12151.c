#include <stdio.h>

int sugar[1005][1005];

int main() {
  int rowMax[1005];
  int colMin[1005] = {__INT_MAX__};
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &sugar[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    int rowTemp = 0;
    for (int j = 0; j < n; j++)
    {
      if(i == 0)
        colMin[j] = sugar[i][j];
      else {
        if (sugar[i][j] < colMin[j])
          colMin[j] = sugar[i][j];
      }
      
      if (sugar[i][j] > rowTemp)
        rowTemp = sugar[i][j];
    }
    rowMax[i] = rowTemp;
  }
  for(int i = 0; i < n; i++){
    printf("%d ", rowMax[i]);

  }
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", colMin[i]);
  }
  printf("\n");
}