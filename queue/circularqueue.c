#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = node;
    return node;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    q->rear->next = q->front;
}

int deQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty");
        return -1;
    }

    int item = q->front->data;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next= q->front;
        free(temp);
    }
    return item;
}