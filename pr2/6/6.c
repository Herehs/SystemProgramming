#include <stdio.h>





int main(void){
    FILE *file_1, *file_2, *file_3;
    char name1[30], name2[30], name3[30], string[256];

    scanf("%s", name1);
    scanf("%s", name2);
    scanf("%s", name3);


    if ((file_1 = fopen(name1, "r")) == NULL){
        printf("Не удалось открыть файл");
        return 0;
    }
    if ((file_2 = fopen(name2, "r")) == NULL){
        printf("Не удалось открыть файл");
        fclose(file_1);
        fclose(file_2);
        return 0;
    }
    if ((file_3 = fopen(name3, "w")) == NULL){
        printf("Не удалось открыть файл");
        fclose(file_1);
        fclose(file_2);
        fclose(file_3);
        return 0;
    }

    while(fgets(string, 256, file_1) != NULL){
        fputs(string, file_3);
    }
    fclose(file_1);
    fputs("\n", file_3);

    while(fgets(string, 256, file_2) != NULL){
        fputs(string, file_3);
    }
    
    fclose(file_2);
    fclose(file_3);
    getchar();

    return 0;
}