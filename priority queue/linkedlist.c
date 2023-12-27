#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    int priority;
    struct node *front,*rear;
};

struct priorityqueue{
    int n;
    struct queue *array;
};

struct node *getnode(int data){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

struct queue *getqueue(int priority){
    struct queue *p=(struct queue*)malloc(sizeof(struct queue));
    p->priority=priority;
    p->front=NULL;
    p->rear=NULL;
    return p;
}

struct priorityqueue *getpriorityqueue(int n){
    struct priorityqueue *p=(struct priorityqueue*)malloc(sizeof(struct priorityqueue));
    p->n=n;
    p->array=(struct queue*)malloc(sizeof(struct queue)*n);
    for(int i=0;i<n;i++){
        p->array[i] = getqueue(i+1);
    }
    return p;
}

void insert(struct priorityqueue *p, int data, int priority) {
    struct node *q = getnode(data);
    if (p->array[priority - 1].front == NULL) {
        p->array[priority - 1].front = q;
        p->array[priority - 1].rear = q;
    } else {
        p->array[priority - 1].rear->next = q;
        p->array[priority - 1].rear = q;
    }
}

void delete(struct priorityqueue *p) {
    int i = 0;
    while (i < p->n && p->array[i].front == NULL) {
        i++;
    }
    if (i == p->n) {
        printf("Underflow\n");
    } else {
        struct node *q = p->array[i].front;
        p->array[i].front = p->array[i].front->next;
        free(q);
    }
}


void display(struct priorityqueue *p) {
    for (int i = 0; i < p->n; i++) {
        printf("Priority %d: ", i + 1);
        struct node *q = p->array[i].front;
        while (q != NULL) {
            printf("%d", q->data);
            q = q->next;
            if (q != NULL) {
                printf("->");
            }
        }
        printf("NULL\n");
    }
}



int main(){
    printf("Enter the no of priorities:");
    int n;
    scanf("%d",&n);
    struct priorityqueue *p=getpriorityqueue(n);
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case 1:
                printf("Enter the data:");
                int data;
                scanf("%d",&data);
                printf("Enter the priority:");
                int priority;
                scanf("%d",&priority);
                insert(p,data,priority);
                break;
            case 2:
                delete(p);
                break;
            case 3:
                display(p);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Enter the choice:");
        scanf("%d",&choice);
    }
    return 0;
}