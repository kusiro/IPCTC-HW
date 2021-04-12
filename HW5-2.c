#include <stdio.h>
#include <stdlib.h>

int array[5005];
int main() {
  int query, n, m, k, noControl, tail, ans;
  scanf("%d", &query);
  for(int i = 0; i < query; i++) {
    scanf("%d %d %d", &n, &m, &k);
    noControl = m - 1 - k;
    for(int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
    }

    for(int i = 0; i <= k; i++) {
      int temp = MAXI;
      for(int j = 0; j <= noControl; j++) {
        tail = abs(k - i) + abs(noControl - j);

        if(array[i + j] > array[n - 1 - tail] && ans >= array[i + j]) {
          ans = array[i + j];
        }
          
        else if(array[i + j] <= array[n - 1 - tail] && ans >= array[n - 1 - tail]) {
          ans = array[n - 1 - tail];
        }
      }

    }
    printf("%d\n", ans);
  }
}
  