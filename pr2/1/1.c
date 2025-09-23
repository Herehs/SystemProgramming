#include <stdio.h>
#include <string.h>



int main(void){
    FILE *file_1;
    char name[] = "1.txt";
    char string[128];
    


if ((file_1 = fopen(name, "r")) == NULL){
    printf("Не удалось открыть файл");
    getchar();
    return 0;
}
char substring[128] = "";
scanf("%s", substring);

while(fgets(string, 128, file_1) != NULL)
{
    if(strstr(string, substring) != NULL){
        printf("%s", string);
    }
}

fclose(file_1);
getchar();

return 0;
}