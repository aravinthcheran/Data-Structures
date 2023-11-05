#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* getnode(int data) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void display(struct node* start) {
    struct node* current;
    current = start;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n"); 
}

void insertatend1(struct node* p) {
    int data;
    struct node* newnode;
    printf("Enter the data (enter -1 to stop): ");
    scanf("%d", &data);
    while (data != -1) {
        newnode = getnode(data);
        p->next = newnode;
        p = p->next;
        printf("Enter the data (enter -1 to stop): ");
        scanf("%d", &data);
    }
}

void freeLinkedList(struct node* start) {
    struct node* current = start;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int data;
    struct node* start;
    printf("Enter the data for the first node: ");
    scanf("%d", &data);
    start = getnode(data);
    insertatend1(start);
    display(start);

    return 0;
}
