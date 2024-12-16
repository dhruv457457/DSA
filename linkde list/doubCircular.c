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

// Function to insert a new node at the end of the circular doubly linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, point the new node to itself
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        // Find the last node
        Node* last = (*head)->prev;

        // Update pointers to insert the new node at the end
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
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
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node with specific data\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(&Start, data);
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
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
