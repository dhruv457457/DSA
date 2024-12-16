#include <stdio.h>
#include <stdlib.h>

// Stack structure with dynamic array
struct stack {
    int top;
    int capacity; // Current capacity of the stack
    int *stack;   // Pointer to the stack array
};

typedef struct stack st;

// Function to create a stack
void createStack(st *ps) {
    ps->top = -1;
    ps->capacity = 1; // Initial capacity
    ps->stack = (int *)malloc(ps->capacity * sizeof(int)); // Allocate initial memory
}

// Function to check if the stack is empty
int isEmpty(st *ps) {
    return ps->top == -1;
}

// Function to check if the stack is full
int isFull(st *ps) {
    return ps->top == ps->capacity - 1;
}

// Function to push an element onto the stack
void push(st *ps, int val) {
    if (isFull(ps)) {
        // Double the capacity if the stack is full
        ps->capacity *= 2;
        ps->stack = (int *)realloc(ps->stack, ps->capacity * sizeof(int));
    }
    ps->stack[++ps->top] = val; // Increment top and add value
}

// Function to pop an element from the stack
void pop(st *ps) {
    if (isEmpty(ps)) {
        printf("Stack is empty\n");
        return;
    }
    int temp = ps->stack[ps->top--]; // Get the top element and decrement top
    printf("Popped element: %d\n", temp);
}

// Function to show stack elements
void show(st *ps) {
    if (isEmpty(ps)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = ps->top; i >= 0; i--) {
        printf("%d\n", ps->stack[i]);
    }
}

// Function to peep at a specific position in the stack
void peep(st *ps, int position) {
    if (position < 1 || position > ps->top + 1) {
        printf("Value not found\n");
        return;
    }
    printf("Element at position %d is %d\n", position, ps->stack[ps->top - position + 1]);
}

// Function to get the top element of the stack
int top(st *ps) {
    if (isEmpty(ps)) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value or handle as needed
    }
    return ps->stack[ps->top]; // Return the top element
}

// Main function
int main() {
    st s;
    createStack(&s);
        
    int num, ch;
    do {
        printf("\nEnter your choice\n1. Push\n2. Pop\n3. Show\n4. Peep\n5. Top\n0. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter your number: ");
                scanf("%d", &num);
                push(&s, num);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                show(&s);
                break;
            case 4:
                printf("Enter the position you want to peep: ");
                scanf("%d", &num);
                peep(&s, num);
                break;
            case 5: {
                int topElement = top(&s);
                if (topElement != -1) {
                    printf("Top element: %d\n", topElement);
                }
                break;
            }
            case 0:
                free(s.stack); // Free allocated memory before exit
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    } while (1);
}
