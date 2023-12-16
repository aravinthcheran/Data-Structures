#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to implement a queue using two stacks
// Create two stacks to implement a queue
struct Stack* stack1 = createStack(1000);
struct Stack* stack2 = createStack(1000);

void enqueue(int x) {
    // Push item onto the first stack
    push(stack1, x);
}

int dequeue() {
    // If both stacks are empty, return error
    if (isEmpty(stack1) && isEmpty(stack2)) {
        printf("Q is empty");
        return INT_MIN;
    }

    // If stack2 is empty and stack1 has elements, pop all items from stack1 and push them to stack2
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            push(stack2, pop(stack1));
        }
    }

    // Pop the top item from stack2 and return it
    return pop(stack2);
}
int main() {
    // Enqueue elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Dequeue elements
    printf("%d dequeued from queue\n", dequeue());
    printf("%d dequeued from queue\n", dequeue());
    printf("%d dequeued from queue\n", dequeue());

    return 0;
}