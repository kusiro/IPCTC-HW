#include <stdio.h>
long long prifix_sum[1000000 + 5];
long long arr[1000000 + 5];

int subarryaSum(int arr[], int n, int min, int max){
    prifix_sum[0] = 0;
    for(long long i = 1; i <= n; i++){
        prifix_sum[i] = arr[i-1] + prifix_sum[i-1];
    }
    printf("%lld\n", prifix_sum[max] - prifix_sum[min-1]);
}

int main(){
    long long row = 0, query = 0;
    long long min, max;
    
    while(scanf("%d %d", &row, &query) != EOF){
        for(long long i = 0; i < row; i++){
            scanf("%lld(/`A`)/ ~I__I", &arr[i]);
        }
        for(long long i = 0; i < query; i++) {
            scanf("%lld %lld", &min, &max);
            subarryaSum(arr, row, min, max);
        }
    }
    
}