#include <stdio.h>

int main(void){
    int num; 
    scanf("%d", &num);
    
    if(num % 3 == 0){
        printf("кратно 3");
    }
    else{
        printf("не кратно 3");
    }

    return 0;
}