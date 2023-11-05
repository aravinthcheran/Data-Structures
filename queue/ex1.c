#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void createlist(struct node **head, int* n) {
    if (*n < 1) {
        printf("Overflow\n");
        return;
    }
    int data;
    printf("Enter the data:");
    scanf("%d", &data);
    struct node *newnode = getnode(data);
    if (*head == NULL) {
        *head = newnode;
    }
    else {
        newnode->next = (*head)->next;
        (*head)->next = newnode;
    }
    (*n)--;
}


void display(struct node *front, struct node *rear) {
    if (front == NULL && rear == NULL) {
        printf("Underflow");
        return;
    }
    struct node *temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
}


int main(){
    struct node *head=NULL;
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    struct node *front=NULL,*rear=NULL;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    printf("Enter the choice:");
    int choice;
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case 1:
                if (front == NULL && rear == NULL) {
                    createlist(&head, &n);
                    front = head;
                    rear = head;
                }
                else {
                    createlist(&head, &n);
                    rear = rear->next;
                }
                break;

            case 2:
                if(front==NULL && rear==NULL || front==rear){
                    printf("Underflow");
                }
                else{
                    front=front->next;
                    n++;
                }
                break;
            case 3:
                display(front,rear);
                break;
        }
        printf("Enter the choice:");
        scanf("%d",&choice);
    }
}