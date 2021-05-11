#include <stdio.h>
// #include "function.h"

#define ll long long int
int input[(int)2e6];

int BS(int *array, int q, int n)
{
	if(n > 0){
        if(array[n / 2] == q) {
            return &array[n/2] - &input[0];
        }
        else if(q > array[n / 2]){
            if(n % 2 == 0)
                BS(&array[n / 2], q, n / 2);
            else
                BS(&array[n / 2 + 1], q, n / 2);
        } else {
            BS(array, q , n / 2);
        }
    }
}

int main() {
    int n, t;
    scanf( "%d%d", &n, &t );
    for( int i = 0 ; i < n ; i++ ) {
        scanf( "%d", &input[i] );
    }
    for( int i = 0 ; i < t ; i++ ){
        int q;
        scanf( "%d", &q );
        printf( "%d is at index: %d\n", q, BS(input, q, n) );
    }
    
    
    
    return 0;
}


