#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    int year;
};

struct Node {
    struct Book *book;
    struct Node *next;
};

int main(void) {
    struct Node *first = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));

    struct Book book1 = {"Архитектура компьютера", "Э. Танненбаум", 2013};
    struct Book book2 = {"Война и мир", "Л. Толстой", 1869};

    first->book = &book1;
    second->book = &book2;

    first->next = second;
    second->next = NULL;


    struct Node *p = first;
    while(p != NULL) {
        printf("Название: %s\n", p->book->title);
        printf("Автор: %s\n", p->book->author);
        printf("Год: %d\n\n", p->book->year);
        p = p->next;
    }

    free(first);
    free(second);
    return 0;
}
