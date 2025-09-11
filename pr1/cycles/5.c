#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    for(int i = num; i > 0; --i){
        if(num % i == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}