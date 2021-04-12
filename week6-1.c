#include <stdio.h>

long long int t[1000005], ans[1000005];
int a[1000005], b[1000005], c[1000005];
int value[1000005];
int i, j, n,q;
int main(void) {
	t[0]=0;
	a[0]=0;
	b[0]=0;
	c[0]=0;
	value[0]=0;
	ans[0]=0;//嘗試初始化
	
	scanf("%d%d", &n, &q);//n組寶物 q行數列
	for (i = 1; i < n+1; i++) {
		scanf("%lld", &value[i]);//輸入n組寶物價值 從value[1]開始
	}

	for (i = 1; i < q+1; i++) {

			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);//輸入q行數列 各從a[1]b[1]c[1]開始
		}
	
	for (i = 1; i < n + 1; i++) {
		

		if (value[i] > 0) {
			t[i] = t[i-1] + value[i];//寶物價值>0的用前綴和加總
		}
		else {
			
			t[i] = t[i-1];//<0的寶物價值不變
		}

	}
	
	for (i = 1; i < q+1; i++)
        {
			ans[i] = t[a[i]+c[i]-1] - t[a[i]-1];//t[a+c-1]-t[a-1]發現條件判斷好像用不到b
			//printf("%lld\n", ans[i]);
        }
	for (i = 1; i < q+1; i++)
        {
			//ans[i] = t[a[i]+c[i]-1] - t[a[i]-1];
			printf("%lld\n", ans[i]);//從i=1開始輸出
        }
	return 0;



	}
