#include <stdio.h>
#include <stdlib.h>

long long int a[100000005];

long long int binarySort(long long int target, long long int start, long long int end){
  if(start > end)
    return -1;
  long long int mid = (start + end) / 2;
  if(a[mid] == target)
    return mid;
  if(a[mid] > target){
    return binarySort(target, start, mid);
  }
  if (a[mid] < target){
    return binarySort(target, mid, end);
  }
}

int main() {
  long long int n, t;
  long long int target;
  scanf("%lld%lld", &n, &t);
  for(long long int i = 0; i < n; i++){
    scanf("%lld", &a[i]);
  }
  for(long long int i = 0; i < t; i++){
    scanf("%lld", &target);

    long long int ans = binarySort(target, 0, n-1);
    printf("%lld is at index: %lld\n", target, ans);
  }
}