#include <stdio.h>

int main() {
    const char *path = "/tmp/practice/text file.txt";

    printf("Проверка чтения\n");
    FILE *r = fopen(path, "r");
    if (!r) {
        perror("Чтение невозможно");
    } else {
        printf("Чтение проводится успешно\n");
        fclose(r);
    }

    printf("\nПроверка записи\n");
    FILE *w = fopen(path, "a");
    if (!w) {
        perror("Запись невозможна");
    } else {
        printf("Запись возможна\n");
        fclose(w);
    }

    return 0;
}