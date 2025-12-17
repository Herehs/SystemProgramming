#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100
#define RECORD_SIZE 64

typedef struct {
    char name[32];
    char desc[32];
} Course;

void lock_records(int fd, short type, int start, int count) {
    struct flock lock;
    lock.l_type = type;
    lock.l_whence = SEEK_SET;
    lock.l_start = start * RECORD_SIZE;
    lock.l_len = count * RECORD_SIZE;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLK, &lock);
}

int main() {
    int fd = open("courses.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    Course c;
    int i = 0;

    /* Запрет чтения с 1 по 5 записи */
    lock_records(fd, F_RDLCK, 0, 5);

    printf("После запрета чтения 1–5 записей:\n");
    lseek(fd, 0, SEEK_SET);
    while (read(fd, &c, RECORD_SIZE) > 0) {
        printf("%s %s\n", c.name, c.desc);
    }

    /* Разрешить чтение со 2 по 7 записи */
    lock_records(fd, F_UNLCK, 1, 6);

    printf("\nПосле разрешения чтения 2–7 записей:\n");
    lseek(fd, 0, SEEK_SET);
    while (read(fd, &c, RECORD_SIZE) > 0) {
        printf("%s %s\n", c.name, c.desc);
    }

    /* Подсчёт доступных записей */
    int available = 0;
    struct flock test;

    for (i = 0; i < 10; i++) {
        test.l_type = F_RDLCK;
        test.l_whence = SEEK_SET;
        test.l_start = i * RECORD_SIZE;
        test.l_len = RECORD_SIZE;

        if (fcntl(fd, F_GETLK, &test) == 0 && test.l_type == F_UNLCK) {
            available++;
        }
    }

    printf("\nДоступных записей: %d\n", available);

    close(fd);
    return 0;
}
