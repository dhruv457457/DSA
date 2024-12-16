#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int p,q;
    struct Node* next;

};
typedef struct Node Node;

Node* createNode(int coefficient, int power) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->q = coefficient;
    ptr->p = power;
    ptr->next = NULL;
    return ptr;
}

void traversal(Node* head) {
    printf("Polynomial: ");
    while (head != NULL) {
        printf("%dx^%d ", head->q, head->p);
        head = head->next;
        if (head != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}
Node* createlist(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int coefficient, power;
    
    if (n <= 0) {
        printf("Error: Value should be greater than 0\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &power);
        newNode = createNode(coefficient, power);
        
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    return head;
}
    
void addlist(Node* A,Node* B,Node* C){
     Node *temp = NULL;
   
    *C = NULL;
    while (A != NULL && B != NULL) {
        Node* newNode;

        if (A->p == B->p) {
            newNode = createNode(A->q + B->q, A->p);
            A = A->next;
            B = B->next;
        } else if (A->p > B->p) {
            newNode = createNode(A->q, A->p);
            A = A->next;
        } else {
            newNode = createNode(B->q, B->p);
            B = B->next;
        }

        if (*C == NULL) {
            *C = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

  while (A != NULL) {
        Node* newNode = createNode(A->q, A->p);
        temp->next = newNode;
        temp = newNode;
        A = A->next;
    }

    while (B != NULL) {
        Node* newNode = createNode(B->q, B->p);
        temp->next = newNode;
        temp = newNode;
        B = B->next;
    }
}

int main() {
    int n;

    printf("Enter number of terms for Polynomial A: ");
    scanf("%d", &n);
    Node* A = createlist(n);
    
    printf("Enter number of terms for Polynomial B: ");
    scanf("%d", &n);
    Node* B = createlist(n);
    
    printf("Polynomial A: ");
    traversal(A);
    
    printf("Polynomial B: ");
    traversal(B);
    
    Node* C = NULL;
    addlist(A, B, &C);  

    printf("Sum of Polynomials: ");
    traversal(C);

    return 0;
}