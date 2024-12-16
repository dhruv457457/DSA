#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STACK {
    int size;
    int top;
    char* arr;
};
typedef struct STACK STACK;

int stacktop(STACK* st) {
    return st->arr[st->top];
}

int isempty(STACK* ptr) {
    if (ptr->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isfull(STACK* ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(STACK* ptr, char val) {
    if (isfull(ptr)) {
        printf("Stack Overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(STACK* ptr) {
    if (isempty(ptr)) {
        printf("Stack Underflow\n");
        return -1; 
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int preced(char ptr) {
    if (ptr == '/' || ptr == '*') {
        return 3;
    } else if (ptr == '+' || ptr == '-') {
        return 2;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        return 1;
    else
        return 0;
}

char* infixtopost(char* infix) {
    STACK* sp = (STACK*)malloc(sizeof(STACK));
    sp->size = 100; 
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int j = 0; 
    int i = 0;  

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            while (!isempty(sp) && preced(infix[i]) <= preced(stacktop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (!isempty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0'; 
    return postfix;
}

int main() {
    char* infix = "x-y/z-k*d";
    printf("Postfix is: %s\n", infixtopost(infix));
    return 0;
}
