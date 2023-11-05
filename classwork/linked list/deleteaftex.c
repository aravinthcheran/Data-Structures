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
void deleteafternodex(struct node *p)
{
    int x;
    printf("Enter the node after which you want to delete:");
    scanf("%d",&x);
    while(p->next!=NULL)
    {
        if(p->data==x)
        {
            struct node *temp;
            temp=p->next;
            free(temp);
            p->next=NULL;
            continue;
        }
        p=p->next;
    }
        
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
    deleteafternodex(start);
    display(start);
    return 0;
}