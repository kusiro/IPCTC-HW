#include"function.h"

int BS (int *array, int q, int n){
  int l = 0;
  int r = n;
  int ans = 0;
  while(r > l){
    int mid = (l + r)  / 2;
    if(array[mid] > q)
      r = mid;
    else if(array[mid] < q)
      l = mid;
    else {
      ans = mid;
      break;
    }
  }
  return ans;
}
