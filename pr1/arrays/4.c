#include <stdio.h>

int main(void){
    int sum, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for(int i = 0; i < 10; ++i){
        sum += arr[i];
    }
    printf("%d", sum);

    return 0;
}