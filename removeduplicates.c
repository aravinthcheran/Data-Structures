#include<stdio.h>

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

void removeduplicates(struct node **head) {
    struct node *current = *head;

    while (current != NULL) {
        struct node *traverse = current;
        while (traverse->next != NULL) {
            if (current->data == traverse->next->data) {
                struct node *temp = traverse->next;
                traverse->next = traverse->next->next;
                free(temp);
            } else {
                traverse = traverse->next;
            }
        }
        current = current->next;
    }
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
    display(head);
    removeduplicates(&head);
    display(head);
    return 0;
}