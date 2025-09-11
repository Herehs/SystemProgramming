#include <stdio.h>

int main(void){
    for(int i = 0; i <= 100; ++i){
        if (i % 3 == 0){
            printf("%d\n", i);
        }else if (i % 5 == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}