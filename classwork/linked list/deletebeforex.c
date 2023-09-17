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
struct node *deletebeforenodex(struct node *p)
{
    int x;
    printf("\nEnter the node after which you want to delete:");
    scanf("%d",&x);
    struct node *current=p;
    while(current->next!=NULL)
    {
        if(current->next->data==x)
        {
            struct node *temp=p;
            p=current->next;
            free(temp);
            break;
        }
        current=current->next;
    } 
    return p;
}

int main()
{
    int data;
    printf("Enter the start data:");
    struct node *start;
    scanf("%d",&data);
    start=getnode(data);
    insertatend1(start);
    display(start);
    start=deletebeforenodex(start);
    display(start);
}