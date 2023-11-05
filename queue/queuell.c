#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(front == -1 && rear==-1){
        front=rear=0;
        queue[rear]=data;
    }

    else if((rear+1)%N == front)
    {
        printf("Queue is full");
    }

    else {
    rear = (rear+1)%N;
    queue[rear]=data;
    }
}

void dequeue(){
    if(front ==-1 && rear ==-1){
        printf("Queue is empty");
    }
    else if(front == rear){
        printf("The deleted element is:%d ",queue[front]);
        front = rear =-1;

    }
    else{
        printf("The deleted element is:%d\n ",queue[front]);
        front = (front+1)%N;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        int i =front;

        do{
            printf("%d",queue[i]);
            i = (i+1)%N;
        }while(i != rear);
        printf("%d",queue[rear]);
    }
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
}