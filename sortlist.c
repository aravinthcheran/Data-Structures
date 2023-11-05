#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

struct node *sort(struct node *head) {
    struct node *current = head, *index = NULL;
    int temp, flag;
    
    if (head != NULL && head->next != NULL) {
        while (current != NULL) {
            index = current->next;
            flag = 0;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                    flag = 1;
                }
                index = index->next;
            }
            if (flag == 0) {
                break;
            }
            current = current->next;
        }
    }
    
    return head;
}

void display(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct node *p = getnode(data);
        
        if (head == NULL) {
            head = p;
        } else {
            struct node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = p;
        }
    }
    
    printf("Original Linked List: ");
    display(head);

    head = sort(head);

    printf("Sorted Linked List: ");
    display(head);

    return 0;
}
