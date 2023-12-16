#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *getnode(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;
}

void insert(struct node *n)
{
    int data;
    struct node *newnode;
    printf("Enter the data:");
    scanf("%d",&data);
    newnode=getnode(data);
    while(data!=-1)
    {
        n->next=newnode;
        n=n->next;
        printf("Enter the data:");
        scanf("%d",&data);
        newnode=getnode(data);
    }
    printf("Process terminated....");
}

void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL)printf("->");
        temp=temp->next;
    }
}
void deleteaftek(struct node *p)
{
    struct node *new;
    int k;
    printf("Enter the series after which you want to delete:");
    scanf("%d",&k);
    int count=2;
    while(p->next!=NULL)
    {
        if(count==k)
        {
            struct node *temp;
            p->next=p->next->next;
            count=1;
            continue;

        }
        p=p->next;
        count++;
    }
        
}



int main(){
    printf("Enter the data:");
    int n;
    scanf("%d",&n);
    struct node *head=getnode(n);
    insert(head);
    display(head);
    printf("Enter the value of k:");
    int k;
    scanf("%d",&k);
    struct node *new;
    if(k!=1){
        deleteaftek(head);
        display(head);

    }
    display(NULL);
    
}
  