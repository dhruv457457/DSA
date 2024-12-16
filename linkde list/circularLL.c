#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

// Function to insert a new node after a specified item in the circular doubly linked list
void insertPosition(Node** head, int item, int data) {
    Node* ptr = createNode(data);

    // Case when the list is empty
    if (*head == NULL) {
        printf("List is empty. Inserting at head.\n");
        *head = ptr;
        ptr->next = ptr;  
        ptr->prev = ptr;  
        return;
    }

    Node* current = *head;

    // Traverse the list to find the item
    do {
        if (current->data == item) {
            ptr->next = current->next;
            ptr->prev = current;
            current->next->prev = ptr;  // Update the next node's prev pointer
            current->next = ptr;         // Insert new node after current node
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Item %d not found in the list.\n", item);
}

// Function to delete a node with specific data from the circular doubly linked list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = *head;

    // Case 1: Deleting the head node
    if (current->data == data) {
        if (current->next == *head) {  // Only one node in the list
            free(current);
            *head = NULL;
            return;
        } else {
            Node* last = *head;
            // Find the last node
            while (last->next != *head) {
                last = last->next;
            }
            last->next = (*head)->next;  // Link last node to second node
            (*head)->next->prev = last;  // Update the previous link of the new head
            free(*head);  // Free the old head
            *head = last->next;  // Update the head
            return;
        }
    }

    // Case 2: Deleting any other node
    do {
        if (current->data == data) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Item %d not found in the list.\n", data);
}

// Function to print the circular doubly linked list
void print(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    Node* Start = NULL;
    int choice, data, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node after a specific item\n");
        printf("2. Delete a node with specific data\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item after which to insert: ");
                scanf("%d", &item);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertPosition(&Start, item, data);
                break;

            case 2:
                printf("Enter the data of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&Start, data);
                break;

            case 3:
                print(Start);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!
