#include <stdio.h>

int main(void){
    int sum, arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
    arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for(int i = 0; i < 10; ++i){
        sum += arr1[i] + arr2[i];
    }
    printf("%d", sum);

    return 0;
}