#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// function to create a queue of given capacity.
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to implement a stack using two queues
// Create two queues to implement a stack
struct Queue* queue1 = createQueue(1000);
struct Queue* queue2 = createQueue(1000);

// To maintain current number of elements
int curr_size = 0;

void push(int x) {
    curr_size++;

    // Push x first in empty queue2
    enqueue(queue2, x);

    // Push all the remaining elements in queue1 to queue2.
    while (!isEmpty(queue1)) {
        enqueue(queue2, dequeue(queue1));
    }

    // swap the names of two queues
    struct Queue* q = queue1;
    queue1 = queue2;
    queue2 = q;
}

int pop() {
    if (isEmpty(queue1))
        return INT_MIN;
    int x = dequeue(queue1);
    curr_size--;
    return x;
}