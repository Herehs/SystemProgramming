#include <stdio.h>

int main(void){
    int num; 
    scanf("%d", &num);
    
    if(num > 0){
        printf("Положительное");
    }
    else if (num == 0){
        printf("Ноль");
    }
    else if (num < 0){
        printf("Отрицательное");
    }

    return 0;
}