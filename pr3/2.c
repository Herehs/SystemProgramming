#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteMiddle(struct Node **head, int value) {
    struct Node *temp = *head;
    while(temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if(temp == NULL) return; // не найден

    if(temp->prev != NULL && temp->next != NULL) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    struct Node *head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);

    printf("Список: ");
    printList(head);

    deleteMiddle(&head, 30);

    printf("После удаления: ");
    printList(head);

    return 0;
}