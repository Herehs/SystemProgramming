#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){
    FILE *file_1, *file_2, *file_3;
    char name1[] = "1.txt", name2[] = "2.txt", name3[] = "temp.txt";
    char string[128], original[128], changed[128];
    


if ((file_1 = fopen(name1, "r")) == NULL){
    printf("Не удалось открыть файл");
    return 0;
}

if ((file_2 = fopen(name2, "r")) == NULL){
    fclose(file_1);
    fclose(file_2);
    printf("Не удалось открыть файл");
    return 0;
}
if ((file_3 = fopen(name3, "w")) == NULL){
    fclose(file_1);
    fclose(file_2);
    fclose(file_3);
    printf("Не удалось открыть файл");
    return 0;
}

for(int i = 0; i < 2; ++i){
    switch (i)
    {
    case 0:
        if(fgets(original, 128, file_1) == NULL){
            return 0;
        }
        break;
    case 1:
        if(fgets(changed, 128, file_1) == NULL){
            return 0;
        }
    default:
        break;
    }
}

while(fgets(string, 128, file_2) != NULL)
{   
    fputs(string, file_3);
}
fclose(file_3);
fclose(file_2);
fopen(name2, "w");
fopen(name3, "r");

while(fgets(string, 128, file_3) != NULL)
{   
    if(strstr(string, original) != NULL){
        fputs(changed, file_2);
        fputc('\n', file_2);
    }
    else{
        fputs(string, file_2);
    }
}

fclose(file_3);
system("del temp.txt");


fclose(file_1);
fclose(file_2);
return 0;
}