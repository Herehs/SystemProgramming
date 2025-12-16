#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


typedef struct {
    char nick[20];
    int id;
} Reader;

void print_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    Reader r;

    printf("\nСодержимое файла:\n");
    while (fscanf(file, "%s %d", r.nick, &r.id) != EOF) {
        printf("%s %d\n", r.nick, r.id);
    }
    fclose(file);
}
void main(void){
    printf("исходный файл");
    print_file("text.txt");
    printf("\nЗапретить чтение с первой по пятую записи");
    print_file("stage1.txt");
    printf("\nРазрешить чтение второй записи");
    print_file("stage2.txt");
}