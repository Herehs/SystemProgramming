#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    char filename[] = "sss.txt";
    char substring[128];
    char buffer[BUF_SIZE];
    int fd;
    ssize_t bytes_read;
    char *line, *rest;

    printf("Введите подстроку для поиска: ");
    scanf("%s", substring);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Ошибка открытия файла");
        exit(1);
    }

    char temp[BUF_SIZE * 2] = "";  
    while ((bytes_read = read(fd, buffer, BUF_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        strcat(temp, buffer);

        line = strtok_r(temp, "\n", &rest);
        while (line != NULL) {
            
            if (strstr(line, substring) != NULL) {
                write(STDOUT_FILENO, line, strlen(line));
                write(STDOUT_FILENO, "\n", 1);
            }
            line = strtok_r(NULL, "\n", &rest);
        }

        if (temp[strlen(temp) - 1] != '\n') {
            strcpy(temp, rest ? rest : "");
        } else {
            temp[0] = '\0';
        }
    }

    if (bytes_read == -1) {
        perror("Ошибка чтения");
    }

    close(fd);
    return 0;
}
