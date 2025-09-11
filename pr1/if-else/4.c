#include <stdio.h>

int main(void){
    int num1, num2; 
    scanf("%d%d", &num1, &num2);
    
    if(num1 > num2){
        printf("первое число больше");
    }
    else{
        printf("второе число больше");
    }

    return 0;
}