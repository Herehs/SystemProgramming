#include <stdio.h>


void printDivisors(int);

int main(void){
    int num;
    scanf("%d", &num);
    printDivisors(num);
    return 0;
}

void printDivisors(int a){
    for(int i = 1; i <= a; ++i){
        if(a % i == 0){
            printf("%d\n", i);
        }
    }
}

