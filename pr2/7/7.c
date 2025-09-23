#include <stdio.h>
#include <ctype.h>




int main(void){
    FILE *file_1, *file_2;
    char name1[] = "f.txt", name2[] = "newf.txt", letter;


    if ((file_1 = fopen(name1, "r")) == NULL){
        printf("Не удалось открыть файл");
        return 0;
    }

    if ((file_2 = fopen(name2, "w")) == NULL){
        fclose(file_1);
        printf("Не удалось открыть файлw");
        return 0;
    }

    while((letter = fgetc(file_1)) != EOF){
        putc(tolower(letter), file_2);
    }
    

    fclose(file_1);
    fclose(file_2);
    return 0;
}