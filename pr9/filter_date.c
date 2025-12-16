#include <stdio.h>
#include <string.h>

int main(void) {
    char line[1024];
    const char *prefix = "03.05.2024";

    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, prefix, strlen(prefix)) == 0) {
            fputs(line, stdout);
        }
    }
    return 0;
}
