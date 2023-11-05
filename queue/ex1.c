#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data){
    struct node *p=(int*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

void enqueue(struct node **head){
    int data;
    printf("Enter ther data: ");
    scanf("%d",&data);
    struct node *newnode=getnode(data);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

void dequeue(st)