#include <stdio.h>

int main() {
    double a, b;
    int z;
    while(scanf("%lf %lf %d", &a, &b, &z)!=EOF){
        double decimal = ((a * b) - (int)(a * b));

        if(z == 0)
            printf("%d\n", (int)(a * b));
        else {
            printf("%d.", (int)(a * b));
            
            for(int i = 0; i < z; i++){
                decimal *= 10;
                if((int)(decimal) == 0)
                    printf("0");
            }
            if(a * b > 0 && (int)(decimal) != 0)
                printf("%d\n", (int)(decimal));
            else if(a * b < 0 && (int)(decimal) != 0)
                printf("%d\n", (int)(decimal) * -1);
            else
                printf("\n");
        }
        
    }
}