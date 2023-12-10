#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *getnode(int data){
    struct node *p=malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    p->prev=NULL:
    return p;
}

void insertatfront(struct node **head){
    printf("Enter the data:");
    int data;
    scanf("%d",&data);
    struct node *newnode;
    if(*head==NULL){
        *head=getnode(data);
    }
    else{
        newnode=getnode(data);
        newnode->next=*head;
        (*head)->prev=newnode;
        *head=newnode;
    }
}

void insertatrear(struct node **head){
    printf("Enter the data:");
    int data;
    scanf("%d",&data);
    struct node *newnode;
    if(*head==NULL){
        *head=getnode(data);
    }
    else{
        newnode=getnode(data);
        newnode->next=*head;
        newnode->prev=(*head)->prev;
        (*head)->prev=newnode;
    }
}