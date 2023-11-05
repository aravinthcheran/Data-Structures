#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *getnode(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void display(struct node *start)
{
    struct node *current;
    current=start;
    while(current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL");
}
void insertatend(int numberOfElements)
{
    int data;
    struct node *start=NULL,*current,*newnode;
    for(int i=0;i<numberOfElements;i++)
    {
        printf("Enter the data:");
        scanf("%d",&data);
        newnode=getnode(data);
        if(start==NULL)
        {
            start=newnode;
            current=start;
        }
        else
        {
            current->next=newnode;
            current=current->next;
        }
    }
    display(start);
}
void insertatend1(struct node *p)
{
    int data;
    struct node *newnode;
    printf("Enter the data:");
    scanf("%d",&data);
    newnode=getnode(data);
    while(data!=-1)
    {
        p->next=newnode;
        p=p->next;
        printf("Enter the data:");
        scanf("%d",&data);
        newnode=getnode(data);
    }
    
    //display(p);
    
}
void deleteatstart(struct node *p)
{
    struct node *q;
    q=p;
    p=p->next;
    free(q);
    //display(p);
}
int main()
{
    int data;
    //printf("Enter the number of elements:");
    struct node *start;
    scanf("%d",&data);
    start=getnode(data);
    insertatend1(start);
    display(start);
    deleteatstart(start);
    display(start);
    return 0;
}