#include <stdio.h>

int main(){
  int t;
  int n;
  int point[100][3];
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &n);
    for(int j = 0; j < n; j++){
      scanf("%d %d", point[j][0], point[j][1]);
    }
    
  }
}