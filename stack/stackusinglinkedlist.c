#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data){
    struct node *p=malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

void push(struct node **head, int data, int *top, int size){
    if(*top >= size-1){
        printf("Stack Overflow\n");
        return;
    }
    struct node *newnode = getnode(data);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        newnode->next = *head;
        *head = newnode;
    }
    (*top)++;
}

void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void pop(struct node **head, int *top) {
    if (*head == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        (*top)--;
    }
}


int main(){
    struct node *head=NULL;
    int size;
    printf("Enter the size of stack: ");
    scanf("%d",&size);
    int top=-1;
    int choice,data;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                push(&head,data,&top,size);
                break;
            case 2:
                pop(&head,&top);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}