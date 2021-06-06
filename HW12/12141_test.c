#include <stdio.h>
#include <string.h>

char input[1005][1005];
char *ans[1005];

int compare(const void *A, const void *B){
  const char *iOne = *(const char *const *)A;
  const char *iTwo = *(const char *const *)B;
  return (strlen(iOne) - strlen(iTwo));
}

int main(){
  int n;
  int isSub = 1;

  scanf("%d", &n);
  
  for(int i = 0; i < n; i++){
    scanf("%s", input[i]);
    ans[i] = input[i];
  }

  qsort(ans, n, sizeof(char *), compare);

  for (int i = 0; i < n - 1; i++)
  {
    if(strstr(ans[i], ans[i+1]) == NULL){
      isSub = 0;
      break;
    }
  }
  if(isSub){
    printf("YES\n");
    for(int i = 0; i < n; i++){
      printf("%s\n", ans[i]);
    }
  } else {
    printf("NO\n");
  }
}