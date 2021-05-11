#include <stdio.h>

int array[1000];

void test(int *input, int n){
  
  if(n > 0){
    if(n % 2 == 0)
      test(&input[n / 2], n / 2);
    else
      test(&input[n / 2 + 1], n / 2);
  }
    
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  
  test(array, n);
}