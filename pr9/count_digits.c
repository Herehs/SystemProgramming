#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    int digits = 0;

    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            digits++;
        }
    }

    printf("Total digits: %d\n", digits);
    return 0;
}
