#include<stdio.h>
#include<stdlib.h>

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

void insertatfront(struct node **head, int data) {
    struct node *p = getnode(data);
    p->next = *head;
    *head = p;
}

void insertatrear(struct node *head,int data){
    struct node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=getnode(data);
}

void display(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteatfront(struct node **head){
    struct node *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deleteatrear(struct node *head){
    struct node *current=head;
    while(current->next->next!=NULL){
        current=current->next;
    }
    struct node *temp=current->next;
    current->next=NULL;
    free(temp);
}

void deletenodex(struct node **head,int x){
    struct node *current=*head;
    struct node *prev=NULL;
    while(current->data!=x){
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);
}


int main(){
    struct node *head=getnode(1);
    insertatrear(head,2);
    insertatfront(&head,3);
    display(head);
    deleteatrear(head);
    deleteatfront(&head);
    display(head);
}