#include <stdio.h>

int main(void){
    int sum;
    for(int i = 0; i <= 100; ++i){
        sum += i;
    }
    printf("%d", sum);

    return 0;
}