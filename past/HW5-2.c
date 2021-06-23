#include <stdio.h>
#include <stdlib.h>


int main() {
  int query;
  long long int ans = 0;
  scanf("%d", &query);
  for(int i = 0; i < query; i++) {
    int n, m, k, noControl, tail;
    long long int ans = 0;
    long long int array[5005];
    scanf("%d %d %d", &n, &m, &k);
    noControl = m - 1 - k;
    for(int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
    }

    if(m - 1 > k)
    {
      long long int temp = 1000000005;
      for (int i = 0; i <= k; i++)
      {
        for (int j = 0; j <= noControl; j++)
        {
          tail = n - 1 - abs(k - i) - abs(noControl - j);

          if (array[i+j] > array[tail])
          {
            if(array[i+j] < temp)
              temp = array[i + j];
          }
          else
          {
            if(array[tail] < temp)
              temp = array[tail];
          }
        }
        if (temp > ans)
          ans = temp;
      }
    }
    else
    {
      ans = array[0];
      for(int i = 0; i <= m - 1; i++)
      {
        if(array[i] > array[n - 1 - i] && array[i] > ans)
          ans = array[i];
        else if (array[i] < array[n - 1 - i] && array[n - 1 - i] > ans)
          ans = array[n - 1 - i];
      }
    }
    printf("%d\n", ans);
  }
}
  