#include<stdio.h>
#include<stdlib.h>

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

void insertatfront(struct node **head){
    int data;
    printf("Enter ther data: ");
    scanf("%d",&data);
    struct node *newnode=getnode(data);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}

void insertatrear(struct node **head){
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

void deleteatfront(struct node **head){
    if(*head==NULL){
        printf("Underflow");
        return;
    }
    else{
        struct node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void deleteatrear(struct node **head){
    if(*head==NULL){
        printf("Underflow");
        return;
    }
    else{
        struct node *temp=*head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void display(struct node *head){
    if(head==NULL){
        printf("Underflow");
        return;
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    struct node *head=NULL;
    int choice;
    printf("1.Insert at front\n2.Insert at rear\n3.Delete at front\n4.Delete at rear\n5.Display\n0.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case 1:
                insertatfront(&head);
                break;
            case 2:
                insertatrear(&head);
                break;
            case 3:
                deleteatfront(&head);
                break;
            case 4:
                deleteatrear(&head);
                break;
            case 5:
                display(head);
                break;
            default:
                printf("Invalid choice");
        }
        printf("Enter the choice:");
        scanf("%d",&choice);
    }
    return 0;
}