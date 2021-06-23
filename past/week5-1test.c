#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long rows,queries,lowerBound,upperBound;
long long junkA[1000005];
long long ans[100005];


int main()
{
    //讀row 和 queries
    scanf("%lld %lld", &rows, &queries);
    for(long long i = 0;i < rows;i++)
    {
        scanf("%lld(/`A`)/ ~I__I",&junkA[i]);
    }
    //做prefix sum array
    for(long long i = 1;i < rows;i++)
    {
        junkA[i] = junkA[i] + junkA[i-1];
    }
    //開始讀入lower upper bound同時記錄答案
    for(long long i = 0;i < queries;i++)
    {
        scanf("%lld %lld", &lowerBound, &upperBound);
        //printf("low = %d, up = %d\n", lowerBound, upperBound);
        if(lowerBound == 1) //特別狀況
        {
            ans[i] = junkA[upperBound - 1];
        }
        else
        {
            ans[i] = junkA[upperBound - 1] - junkA[lowerBound - 2];
        }
    }
    //輸出答案
    for(long long i = 0;i < queries;i++)
    {
        printf("%lld\n", ans[i]);
    }

    return 0;
}