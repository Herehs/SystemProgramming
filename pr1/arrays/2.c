#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    srand(time(NULL));

    int arr[10];

    for(int i = 0; i < 10; ++i){
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }

    return 0;
}