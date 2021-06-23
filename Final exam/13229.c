#include <stdio.h>
#include <stdlib.h>

int a[100005];
int ok[100005];

int stack[100005];
int top, last;

int get_size() {
    return last - top;
}
void push(int v) {
    stack[++last] = v;
}
int pop() {
    return stack[++top];
}

int main() {

    int n, k, v, next_v, cnt;
    while(scanf("%d %d", &n, &k) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // Init
        for(int i = 0; i < k; i++) {
            ok[i] = 0;
        }
        top = -1;
        last = -1;

        // Init search
        for(int i = 0; i < n; i++) {
            v = a[i] % k;
            if( ok[v] == 0 ) {
                push(v);
                ok[v] = 1;
            }
        }

        // Start search
        while( get_size() > 0 ) {
            v = pop();
            for(int i = 0; i < n; i++) {
                next_v = (v + a[i]) % k;
                if( ok[next_v] == 0 ) {
                    push(next_v);
                    ok[next_v] = 1;
                }
            }
        }

        // Count answer
        cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += ok[i];
        }
        
        printf("%d\n", cnt);
        for(int i=  0; i < k; i++) {
            if( ok[i] == 1 ) {
                (i == k - 1) ? printf("%d", i) : printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
