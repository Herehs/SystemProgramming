#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NAME_LEN 20
#define RECORDS 10

struct Reader {
    char nick[NAME_LEN];
    int id;
};

void print_file(int fd) {
    struct Reader r;
    lseek(fd, 0, SEEK_SET);

    printf("Содержимое файла:\n");
    while (read(fd, &r, sizeof(r)) == sizeof(r)) {
        printf("Ник: %-10s ID: %d\n", r.nick, r.id);
    }
    printf("\n");
}

int count_available(int fd) {
    struct flock lock;
    int count = 0;

    for (int i = 0; i < RECORDS; i++) {
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = i * sizeof(struct Reader);
        lock.l_len = sizeof(struct Reader);

        fcntl(fd, F_GETLK, &lock);

        if (lock.l_type == F_UNLCK) {
            count++;
        }
    }
    return count;
}

int main() {
    int fd = open("readers.bin", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct Reader readers[RECORDS] = {
        {"as",101},{"ds",102},{"fd",103},{"kfggate",104},{"fhfh",105},
        {"fjgfg",106},{"fjth",107},{"vnc",108},{"ww",109},{"ili",110}
    };

    write(fd, readers, sizeof(readers));

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 5 * sizeof(struct Reader);
    fcntl(fd, F_SETLK, &lock);

    printf("После запрета чтения 1–5 записей:\n");
    print_file(fd);

    lock.l_type = F_UNLCK;
    lock.l_start = sizeof(struct Reader);
    lock.l_len = sizeof(struct Reader);
    fcntl(fd, F_SETLK, &lock);

    printf("После разрешения чтения 2-й записи:\n");
    print_file(fd);

    printf("Количество доступных записей: %d\n", count_available(fd));

    close(fd);
    return 0;
}
