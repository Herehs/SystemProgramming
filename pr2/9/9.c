#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}


int main(void){
    FILE *file_1, *file_2, *file_3;
    char name1[] = "1.txt", name2[] = "temp.txt";
    char string[128];
    


if ((file_1 = fopen(name1, "r")) == NULL){
    printf("Не удалось открыть файл");
    return 0;
}

if ((file_2 = fopen(name2, "w")) == NULL){
    fclose(file_1);
    fclose(file_2);
    printf("Не удалось открыть файл");
    return 0;
}


while(fgets(string, 128, file_1) != NULL)
{   
    fputs(string, file_2);
}
fclose(file_2);
fclose(file_1);
file_1 = fopen(name1, "w");
file_2 = fopen(name2, "r");

while(fgets(string, 128, file_2) != NULL)
{   
    string[strcspn(string, "\n")] = '\0';
    qsort(string, strlen(string), sizeof(char), cmp);
    fputs(string, file_1);
    fputc('\n', file_1);
}

fclose(file_2);
system("del temp.txt");


fclose(file_1);
return 0;
}