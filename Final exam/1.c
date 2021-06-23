#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int a[5005];
int test[5005];
int solo_guard[5005];
vector<pair<int, int>> guard;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        guard.clear();
        for (int i = 0; i < 5005; i++)
            a[i] = 0;
        int n, q;
        scanf("%d%d", &n, &q);
        int ans = 0;
        for (int i = 0; i < q; i++)
        {
            pair<int, int> now;
            scanf("%d%d", &now.first, &now.second);
            guard.push_back(now);
            for (int j = now.first; j <= now.second; j++)
                a[j]++;
        }
        int total_guard = 0;
        for (int i = 0; i <= n; i++)
        {
            if (a[i] != 0)
                total_guard++;
        }
        for (int i = 0; i < q; i++)
        {
            int now_guard = total_guard;
            for (int j = 0; j <= n; j++)
                test[j] = a[j];
            int l = guard[i].first;
            int r = guard[i].second;
            for (int j = l; j <= r; j++)
            {
                test[j]--;
                if (test[j] == 0)
                    now_guard--;
            }
            for (int j = 1; j <= n; j++)
            {
                if (test[j] == 1)
                    solo_guard[j] = solo_guard[j - 1] + 1;
                else
                    solo_guard[j] = solo_guard[j - 1];
            }
            for (int j = 0; j < q; j++)
            {
                if (j != i)
                {
                    int now_l = guard[j].first;
                    int now_r = guard[j].second;
                    int real_now_guard = now_guard;
                    real_now_guard -= solo_guard[now_r] - solo_guard[now_l - 1];
                    if (real_now_guard > ans)
                        ans = real_now_guard;
                }
            }
        }
        printf("%d\n", ans);
    }
}