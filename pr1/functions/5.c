#include <stdio.h>


int isNumbersFriendly(int, int);

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%s", isNumbersFriendly(num1, num2) ? "true" : "false");
    return 0;
}

int isNumbersFriendly(int a, int b){
    int sum_a = 0, sum_b = 0;

    for(int i = 1; i < a; ++i){
        if(a % i == 0){
            sum_a += i;
        }
    }

    for(int i = 1; i < b; ++i){
        if(b % i == 0){
            sum_b += i;
        }
    }

    if(sum_b == a){
        if(sum_a == b) return 1;
    }
    else return 0;
}
    


