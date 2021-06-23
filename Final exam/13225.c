#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int L, R;
}range;

range guard[500];

int compare(const void *A, const void *B){
  range a = *(range *)A;
  range b = *(range *)B; 
  if(a.L != b.L)
    return( a.L - b.L);
  else
    return(a.R - b.R);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, q;
    int count = 0;
    int temp;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < q; i++){
      scanf("%d %d", &guard[i].L, &guard[i].R);
    }
    qsort(guard, n, sizeof(range), compare);
    for(int i = 0; i < q; i++){
      printf("%d %d\n", guard[i].L, guard[i].R);
    }
  }
}