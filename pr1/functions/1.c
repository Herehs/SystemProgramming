#include <stdio.h>


int factorial(int);

int main(void){
    int num;
    scanf("%d", &num);
    printf("%d", factorial(num));
    return 0;
}

int factorial(int a){
    if(a > 1){
        return a * factorial(a - 1);
    }
}