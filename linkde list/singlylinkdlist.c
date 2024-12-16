#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node * createNode(int data){
    Node * ptr =(Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void traversal(Node* head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("-> %d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node *search(Node *head,int d){
    Node *temp=head;
    while (temp!=NULL&&temp->data!=d)
    {
        temp=temp->next;
    }
    return temp;
    
}


Node* insertBeggin(Node*head,int data){
    Node* temp=createNode(data);
    temp->next=head;
    head=temp;
    return head;
 
}
void insertEnd(Node**head,int data){
    Node *temp=createNode(data),*head_ii;

    if(*head==NULL){
        *head=temp;
    }
    else{
        head_ii=*head;
        while (head_ii->next!=NULL)
            (head_ii)=(head_ii)->next;
     (head_ii)->next=temp;
    }
}

void insertatPlace(Node ** head,int d,int iteme){
  Node *temp=createNode(d);
  Node *ptr = *head;
  Node *found_node = search(ptr, iteme);
  if(found_node!=NULL){
    temp->next=found_node->next;
    found_node->next=temp;
  }
  else{
    printf("Value not found");
  }
    
}

void deleteatStart(Node **head){
    Node *temp=*head;
    
    (*head)=(*head)->next;
    free(temp);
}
void deleteEnd(Node**head){
    Node* temp=*head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;

}
void deleteValue(Node **head,int item){
    Node *loc,*ptr;
    ptr=*head;
    if(ptr->data==item){
        *head=ptr->next;
        free(ptr);
    
    }
    loc=search(*head,item);
    if(loc==NULL){
        printf("Value not found");
    }
    ptr->next=loc->next;
    free(ptr);
}

void Reverse(Node **head){
    Node*next=NULL;
    Node*prev=NULL;
    while (*head!=NULL)
    {
        next=(*head)->next;
        (*head)->next=prev;
        prev=*head;
        *head=next;
    }
    *head=prev;
}

int main(){

    Node *Start=NULL;
    int choice,b,c;
    do
    {
        
    printf("Slect opertion u want to perform\n1 Insertion begging\n2 Insertion end\n3 Inesrtion at postion\n4 Deletion of first node\n5 Deltion last node\n6 Delete  specific value\n7 traverse linkdlist\n8 Reverse a lindlisr\n9 exit\n enter ur choice");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
       printf("Enter Value  ");
       scanf("%d",&b);
       Start=insertBeggin(Start,b);
        break;
     case 2:
       printf("Enter value ");
       scanf("%d",&b);
       insertEnd(&Start,b);
        break;
     case 3:
       printf("Enter The value after which u wanna instert ur data and after put ur data ");
       scanf("%d",&c);
       scanf("%d",&b);
       insertatPlace(&Start,b,c);
        break;
     case 4:
       
       printf("Your 1st is node is deleted\n ");
            deleteatStart(&Start);
        break;
     case 5:
       
       printf("Your last is node is deleted\n ");
            deleteEnd(&Start);
        break;
     case 6:
       
       printf("Enter value from lindlist which wanna delte: ");
            scanf("%d",&c);
            deleteValue(&Start,c);
        break;
     case 7:
       Reverse(&Start);
       printf("Your list is reversed");
       traversal(Start);
          
        break;
      case 8:
       traversal(Start);
        break;
    
       default:
        printf("your input is not in menu");
        break;
    }
    } while (choice!=9);

     Node* temp;
    while (Start != NULL) {
        temp = Start;
        Start = Start->next;
        free(temp);
    }

    return 0;
}