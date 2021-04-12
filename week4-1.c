#include <stdio.h>

int main(){
    double A, B, C, addAll;

    while(scanf("%lf %lf %lf", &A, &B, &C)!=EOF){
        addAll = (A + B + C) / 2;
        printf("%.0lf %.0lf %.0lf\n", addAll - B, addAll - C, addAll -A);
    }
}