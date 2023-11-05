#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

void display(struct node *head){
    struct node *current=head;
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}


struct node* reverse(struct node *head)
{
    struct node *next=NULL,*prev=NULL,*current=head;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}


int main(){
    struct node *head=NULL;
    int n;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        struct node *p=getnode(data);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            struct node *current=head;
            while (current->next!=NULL)
            {
                current=current->next;
            }
            current->next=p;
        }            
    }
    struct node *reversed=reverse(head);
    display(reversed);
}