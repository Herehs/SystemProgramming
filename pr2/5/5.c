#include <stdio.h>



int main(void){
    FILE *file_1;
    char name[] = "5.txt";


    if ((file_1 = fopen(name, "r")) == NULL){
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }

    int num, count = 0;
    while(fscanf(file_1, "%d", &num) == 1){
        if(num % 2 == 0){
            if (num > 0)
            {
                ++count;
            }
            
        }
    }
    printf("%d", count);

    fclose(file_1);
    getchar();

    return 0;
}