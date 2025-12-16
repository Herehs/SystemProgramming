#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORDS 10
#define REC_SIZE 32

struct Reader {
    char nick[20];
    int id;
};

void copy_file(const char *src, const char *dst) {
    int in = open(src, O_RDONLY);
    int out = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[128];
    int n;

    while ((n = read(in, buf, sizeof(buf))) > 0)
        write(out, buf, n);

    close(in);
    close(out);
}

void lock_record(int fd, int rec, short type) {
    struct flock lock;
    lock.l_type = type;
    lock.l_whence = SEEK_SET;
    lock.l_start = rec * REC_SIZE;
    lock.l_len = REC_SIZE;
    lock.l_pid = getpid();
    fcntl(fd, F_SETLK, &lock);
}

int main() {
    int fd;
    struct Reader r;
    char buffer[REC_SIZE];
    int i, count = 0;

    copy_file("text.txt", "stage1.txt");
    fd = open("stage1.txt", O_RDWR);

    for (i = 0; i < 5; i++) {
        lock_record(fd, i, F_RDLCK);
    }

    close(fd);

    copy_file("stage1.txt", "stage2.txt");
    fd = open("stage2.txt", O_RDWR);

    lock_record(fd, 1, F_UNLCK);

    close(fd);

    copy_file("stage2.txt", "stage3.txt");
    fd = open("stage3.txt", O_RDONLY);

    for (i = 0; i < RECORDS; i++) {
        struct flock lock;
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = i * REC_SIZE;
        lock.l_len = REC_SIZE;
        lock.l_pid = getpid();

        if (fcntl(fd, F_GETLK, &lock) == 0) {
            if (lock.l_type == F_UNLCK)
                count++;
        }
    }

    close(fd);

    FILE *f = fopen("count.txt", "w");
    fprintf(f, "%d\n", count);
    fclose(f);

    return 0;
}
