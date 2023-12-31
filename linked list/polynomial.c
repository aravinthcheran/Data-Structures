#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};

struct mode *getnode(int coeff, int exp){
    struct node *p=malloc(sizeof(struct node));
    p->coeff=coeff;
    p->exp=exp;
    p->next=NULL;
    return p;
}

void insert(struct node **head, int coeff, int exp){
    struct node *temp=getnode(coeff, exp);
    if(*head==NULL){
        *head=temp;
    }
    else{
        struct node *current=*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
}

struct node *addpoly(struct node *poly1, struct node *poly2){
    struct node *temp1=poly1,*temp2=poly2, *result=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp>temp2->exp){
            insert(&result, temp1->coeff, temp1->exp);
            temp1=temp1->next;
        }
        else if(temp1->exp<temp2->exp){
            insert(&result, temp2->coeff, temp2->exp);
            temp2=temp2->next;
        }
        else{
            insert(&result, temp1->coeff+temp2->coeff, temp1->exp);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        insert(&result, temp1->coeff, temp1->exp);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insert(&result, temp2->coeff, temp2->exp);
        temp2=temp2->next;
    }
    return result;
}

void display(struct node *head){
    struct node *current=head;
    while(current!=NULL){
        printf("%dx^%d", current->coeff, current->exp);
        if(current->next!=NULL){
            printf("+");
        }
        current=current->next;
    }
    printf("\n");
}

int main(){
    struct node *poly1=NULL, *poly2=NULL, *result=NULL;
    int n1, n2;
    printf("Enter the number of terms in polynomial 1:");
    scanf("%d", &n1);
    printf("Enter the number of terms in polynomial 2:");
    scanf("%d", &n2);
    printf("Enter the terms of polynomial 1:\n");
    for(int i=0; i<n1; i++){
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }
    printf("Enter the terms of polynomial 2:\n");
    for(int i=0; i<n2; i++){
        int coeff, exp;
        printf("Enter the coefficient and exponent of term %d:", i+1);
        scanf("%d%d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }
    printf("Polynomial 1:");
    display(poly1);
    printf("Polynomial 2:");
    display(poly2);
    result=addpoly(poly1, poly2);
    printf("Result:");
    display(result);
    return 0;
}