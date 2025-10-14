#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char *filepath = "C:\\Program Files\\test_file.txt";
    FILE *file = fopen(filepath, "w");

    if (file == NULL) {
        perror("Нельзя открыть файл");
        return errno;
    }

    printf("Файл успешно открыт.\n");
    fclose(file);

    return 0;
}