#include <stdio.h>


void printNUmbersBetween(int, int);

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printNUmbersBetween(num1 ,num2);
    return 0;
}

void printNUmbersBetween(int a, int b){
    int max, min;
    if(a > b){
        max = a;
        min = b;
    }
    else if(a < b){
        max = b;
        min = a;
    }
    else if(a = b){
        return;
    }

    for(int i = min + 1; i < max; ++i){
        printf("%d ", i);
    }
}


