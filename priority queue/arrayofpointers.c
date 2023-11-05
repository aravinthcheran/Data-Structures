#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front,rear;
    int *array;
    int priority;
};

struct queue* getqueue(int sizeofqueue,int priority){
    struct queue *p=(struct queue*)malloc(sizeof(struct queue));
    p->array=(int*)malloc(sizeof(int)*sizeofqueue);
    p->front=-1;
    p->rear=-1;
    p->priority=priority;
    return p;
}

void enqueue(struct queue *q, int data,int sizeofqueue) {
    
    if (q->rear == -1 && q->front == -1) {
        q->front = 0;
        q->rear = 0;
        q->array[q->rear] = data;
    } else {
        if (q->rear < sizeofqueue - 1) {
            q->rear++;
            q->array[q->rear] = data;
        } else {
            printf("Overflow\n");
        }
    }
}

int dequeue(struct queue *p){
    
        int data=p->array[p->front];
        if(p->front==p->rear){
            p->front=-1;
            p->rear=-1;
        }
        else{
            p->front++;
        }
        return data;
}

int main(){
    printf("Enter the no of priorities:");
    int n;
    scanf("%d",&n);
    struct queue *array1[n];
    int sizeofqueue;
    printf("Enter the size of each queue:");
    scanf("%d",&sizeofqueue);
    for(int i=0;i<n;i++){
        array1[i]=getqueue(sizeofqueue,i+1);
    }
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case 1:{
                int data;
                printf("Enter the data:");
                scanf("%d", &data);
                int priority;               
                printf("Enter the priority (1 to %d):", n);
                scanf("%d", &priority);

                if (priority < 1 || priority > n) {
                    printf("Invalid priority. Must be between 1 and %d.\n", n);
                } else {
                    enqueue(array1[priority - 1], data, sizeofqueue);
                }
                break;
            }

            case 2: {
                for (int i = 0; i < n; i++) {
                    if (array1[i]->front != -1) {
                        printf("Deleted element is %d\n", array1[i]->array[array1[i]->front]);
                        if (array1[i]->front == array1[i]->rear) {
                            array1[i]->front = -1;
                            array1[i]->rear = -1;
                        } else {
                            array1[i]->front++;
                        }
                        break;
                    } else {
                        printf("Underflow\n");
                    }
                }
                break;
            }

            case 3:{
                for(int i=0;i<n;i++){
                    printf("Priority %d:",i+1);
                    for(int j=array1[i]->front;j<=array1[i]->rear;j++){
                        if(array1[i]->front==-1 && array1[i]->rear==-1){
                            printf("Underflow\n");}
                        printf("%d ",array1[i]->array[j]);
                    }
                    printf("\n");
                }
                break;
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
        printf("Enter the choice:");
        scanf("%d",&choice);
    }
}