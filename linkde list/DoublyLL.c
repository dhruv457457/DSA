#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};
typedef struct Node Node;

Node* createNode(int data){
    Node *ptr=(Node*) malloc(sizeof(Node));
    ptr->data=data;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr;
}
void print(Node* head){
    while (head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");   
}

void lengthLL(Node * head){
    int count=0;
       while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
        count++;
    }
    printf("\n Number of items in list %d",count);
}

void insertHead(Node** head,int data){
    Node * temp=createNode(data);
    temp->next=*head;
    (*head)->prev=temp;
    *head=temp;


}




int main(){
    Node * head=createNode(10);
    print(head);
    insertHead(&head,20);
    lengthLL(head);

}