#include <stdio.h>

int a[1005][1005];
int ansRow[1005], ansCol[1005] = {10000};
int main() {
  int n;
  int rowTemp = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    rowTemp = 0;
    for(int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
      if(i == 0) {
        ansCol[j] = a[i][j];
      } else {
        if (a[i][j] < ansCol[j])
          ansCol[j] = a[i][j];
      }
      if(a[i][j] > rowTemp)
        rowTemp = a[i][j];
    }
    ansRow[i] = rowTemp;
  }
  for(int i = 0; i < n; i++){
    (i == n-1) ? (printf("%d", ansRow[i])) : (printf("%d ", ansRow[i]));
  }
  printf("\n");
  for (int i = 0; i < n; i++){
    (i == n - 1) ? (printf("%d", ansCol[i])) : (printf("%d ", ansCol[i]));
  }
  printf("\n");
}