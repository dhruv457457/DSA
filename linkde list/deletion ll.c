#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
typedef struct Node Node;


Node* createNode(int data){
    Node* ptr=(Node*) malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void printL_L(Node* head){
    
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    
}

void insertHead(Node** head,int data ){
    Node * temp=createNode(data);
    temp->next=*head;
    *head=temp;
}

void insertTail(Node ** tail ,int data){
    Node * temp=createNode(data);
    (*tail)->next=temp;
    *tail=temp;
}
void delete(int postion,Node **head){
    Node * temp=*head;
    Node * prev=NULL;
    int count=1;
       if (postion == 1) {
        *head = temp->next; 
        free(temp);
        return;
    }
    while(count<postion){
        prev=temp;
        temp=temp->next;
        count++;
    }
        if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    prev->next=temp->next;
    free(temp);


}



int main(){

    Node * head=createNode(10);
    Node * tail=head;

    printL_L(head);
    insertHead(&head,20);
    insertHead(&head,230);
    insertHead(&head,40);
    printL_L(head);
    insertTail(&tail,30);
    printL_L(head);
    delete(3,&head);
    printL_L(head);

}
    
