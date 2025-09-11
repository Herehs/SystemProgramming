#include <stdio.h>


int isSimpleNumber(int);

int main(void){
    int num;
    scanf("%d", &num);
    printf("%s", isSimpleNumber(num) ? "true" : "false");
    return 0;
}

int isSimpleNumber(int a){
    int count = 0;
    for(int i = 1; i <= a; ++i){
        if(a % i == 0){
            ++count;
        }
    }
    if(count == 2) return 1;
    else return 0;
}
