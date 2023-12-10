#include<stdio.h>
#include<stdlib.h>

struct queue{
    int value[10];
    int priority;
    int front,rear;
};

struct priorityqueue{
    struct queue *array[3];
};

struct queue* getqueue(int priority){
    struct queue *p=(struct queue*)malloc(sizeof(struct queue));
    p->front=-1;
    p->rear=-1;
    p->priority=priority;
    return p;
}

struct priorityqueue* getpriorityqueue(){
    struct priorityqueue *p=(struct priorityqueue*)malloc(sizeof(struct priorityqueue));
    for(int i=0;i<3;i++){
        p->array[i]=getqueue(i+1);
    }
    return p;
}

void enqueue(struct priorityqueue *p, int data,int priority) {   
    if (p->array[priority-1]->rear == -1 && p->array[priority-1]->front == -1) {
        p->array[priority-1]->front = 0;
        p->array[priority-1]->rear = 0;
        p->array[priority-1]->value[p->array[priority-1]->rear] = data;
    } else {
        if (p->array[priority-1]->rear < 10) {
            p->array[priority-1]->rear++;
            p->array[priority-1]->value[p->array[priority-1]->rear] = data;
        } else {
            printf("Overflow\n");
        }
    }
}

int dequeue(struct priorityqueue *p){
    for(int i=0;i<3;i++){
        if(p->array[i]->front!=-1){
            int data=p->array[i]->value[p->array[i]->front];
            if(p->array[i]->front==p->array[i]->rear){
                p->array[i]->front=-1;
                p->array[i]->rear=-1;
            }
            else{
                p->array[i]->front++;
            }
            return data;
        }
    }
}

int main(){
    struct priorityqueue *p=getpriorityqueue();
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case 1:{
                int data,priority;
                printf("Enter the data:");
                scanf("%d",&data);
                printf("Enter the priority:");
                scanf("%d",&priority);
                enqueue(p,data,priority);
                break;
            }
            case 2:{
                int data=dequeue(p);
                printf("The deleted element is:%d\n",data);
                break;
            }
            case 3:{
                for(int i=0;i<3;i++){
                    printf("Priority %d:",i+1);
                    for(int j=p->array[i]->front;j<=p->array[i]->rear;j++){
                        printf("%d ",p->array[i]->value[j]);
                    }
                    printf("\n");
                }
                break;
            }
            default:{
                printf("Invalid choice\n");
            }
        }
        printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
    }
}