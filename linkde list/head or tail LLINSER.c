#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* creatNode(int data) {
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}


void insertTail(struct Node** tail, int d) {
    struct Node* temp = creatNode(d);
    (*tail)->next = temp;
    *tail = temp;



void insertHead(struct Node** head, int d) {
    struct Node* temp = creatNode(d);
    temp->next = *head;
    *head = temp;
}


void print(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void insertIndex(struct Node** head, struct Node** tail, int position, int data) {
 
    if (position == 1) {
        insertHead(head, data);
        return;
    }
    
    struct Node* temp = *head;
    int count = 1;
    

    while (count < position - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }


    if (temp->next == NULL) {
        insertTail(tail, data);
    } else {
       
        struct Node* insert = creatNode(data);
        insert->next = temp->next;
        temp->next = insert;
    }
}

int main() {
    struct Node* head = creatNode(19);
    struct Node* tail = head;

    
    insertTail(&tail, 20);
    insertTail(&tail, 22);
    insertTail(&tail, 21);

    
    print(head);
    printf("\n");

    
    insertIndex(&head, &tail, 3, 33);
    print(head);

    return 0;
}
