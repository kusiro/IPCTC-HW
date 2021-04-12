#include <stdio.h>
long long stack[200005];
long long list[200005];

int main() {
    int amount;
    while(scanf("%d", &amount) != EOF){
        for(int i = 0; i < amount; i++)
            scanf("%d", stack[i]);
        for(int i = 0; i < amount; i++)
            scanf("%d", list[i]);
        for(int i = 0; i < amount; i++){
            for(int j = 0; j < amount; j++){
                if(stack[j] == list[i]){
                    
                }
            }
        }
    }
}