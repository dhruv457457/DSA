#include<stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define the structure for the queue
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

struct BST{
    int data;
    struct BST *left ,*right;
};
typedef struct BST BST;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Enqueue operation (insert element at the end)
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        // If queue is empty, both front and rear will point to the new node
        q->front = q->rear = newNode;
    } else {
        // Add the new node at the end and update the rear pointer
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Dequeue operation (remove element from the front)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Indicates failure
    }
    
    Node *temp = q->front;
    int data = temp->data;
    
    q->front = q->front->next;
    
    // If front becomes NULL, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}


void createTree(BST **root){
    *root =NULL;
}

void preorderRec(BST *tree){
    if(tree!=NULL){
        printf("%d ",tree->data);
        preorderRec(tree->left);
        preorderRec(tree->right);
    }
} 
void inorderRec(BST *tree){
    if(tree!=NULL){
        inorderRec(tree->left);

        printf("%d ",tree->data);
        inorderRec(tree->right);
    }
}
void POSTorderRec(BST *tree){
    if(tree!=NULL){
        POSTeorderRec(tree->left);

        POSTeorderRec(tree->right);
        printf("%d ",tree->data);
    }
}

void levelOrderTraversal(BST *tree){
    Queue *q;
    BST *ptr;
    initQueue(q);
    enqueue(q,tree);
    while (!isEmpty(q))
    {
        ptr=dequeue(q);
        if(ptr->left !=NULL)
        enqueue(q,ptr->left);
        if(ptr->right!=NULL)
        enqueue(q,ptr->right);

    printf("%d ",ptr->info);
    }
    
}

int detemine(BST *tree){
    int leftt,rightt;
    if(tree==NULL)return 0;
    else{
        leftt=detemine(tree->left);
        rightt=detemine(tree->right);
        if(leftt>rightt){
            return ++leftt;
        }
        else {
            return ++rightt;
        }
    }
}

int totalNodes(BST *tree){
    if(tree==NULL){
        return 0;
    }
    else{
        return(totalNodes(tree->left)+totalNodes(tree->right)+1);
    }
}