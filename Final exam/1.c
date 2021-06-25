#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int L, R;
}range;

int a[5005];
int check[5005];
int solo[5005];
range guard[5005];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 5005; i++){
            a[i] = 0;
            guard[i].L = 0;
            guard[i].R = 0;
        }
            
        int n, q;
        scanf("%d %d", &n, &q);
        int ans = 0;
        for (int i = 0; i < q; i++)
        {
            range now;
            scanf("%d%d", &now.L, &now.R);
            guard[i].L = now.L;
            guard[i].R = now.R;
            for (int j = now.L; j <= now.R; j++)
                a[j]++;
        }
        int totalGuard = 0;
        for (int i = 0; i <= n; i++)
        {
            if (a[i] != 0)
                totalGuard++;
        }
        for (int i = 0; i < q; i++)
        {
            int nowGuard = totalGuard;
            for (int j = 0; j <= n; j++)
                check[j] = a[j];
            int l = guard[i].L;
            int r = guard[i].R;
            for (int j = l; j <= r; j++)
            {
                check[j]--;
                if (check[j] == 0)
                    nowGuard--;
            }
            for (int j = 1; j <= n; j++)
            {
                if (check[j] == 1)
                    solo[j] = solo[j - 1] + 1;
                else
                    solo[j] = solo[j - 1];
            }
            for (int j = 0; j < q; j++)
            {
                if (j != i)
                {
                    int now_l = guard[j].L;
                    int now_r = guard[j].R;
                    int realGuard = nowGuard;
                    realGuard -= solo[now_r] - solo[now_l - 1];
                    if (realGuard > ans)
                        ans = realGuard;
                }
            }
        }
        printf("%d\n", ans);
    }
}