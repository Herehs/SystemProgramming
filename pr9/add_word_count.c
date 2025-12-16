#include <stdio.h>
#include <ctype.h>

int count_words(const char *s) {
    int count = 0, in_word = 0;

    while (*s) {
        if (isspace(*s)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        s++;
    }
    return count;
}

int main(void) {
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        int words = count_words(line);
        printf("%s [words: %d]\n", line, words);
    }
    return 0;
}
