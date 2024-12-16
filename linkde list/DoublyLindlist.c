#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next,*prev;
};
typedef struct Node Node;
Node* createNode(int data){
    Node*ptr=(Node*) malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}
void traverFRbeg(Node*head){
    printf("List content: ");
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void InsertPost(Node**head,int data){
    Node* ptr=createNode(data);
    Node *q=*head;
    if(*head==NULL){
    *head=ptr;
    return;
    }
  if (data<=(*head)->data)
  {
    ptr->next=*head;
    (*head)->prev=ptr;
    (*head)=ptr;
    return;
  }
  while(q->next!=NULL&&data>q->next->data){
    q=q->next;
  }
  if(q->next!=NULL){
    ptr->next=q->next;
    q->next->prev=ptr;
    q->next=ptr;
    ptr->prev=q;
  }
  else{
    q->next=ptr;
    ptr->prev=q;
  }
  
  }

void deleteNode(Node**head,int data){
  Node *q,*ptr=*head;
  if(ptr->data==data){
    *head=(*head)->next;
    free(ptr);
    (*head)->prev=NULL;
    return;
  }
  while (ptr->data!=data)
  {
    q=ptr;
    ptr=ptr->next;
    if(ptr->next==NULL){
      printf("value not found");
      return;
    }
  }
  q->next=ptr->next;
  ptr->next->prev=q;
  free(ptr);
}
int main(){
   Node *Start=NULL;
    int choice,b,c;
    do
    {
        
    printf("Slect opertion u want to perform\n1 Inesrtion at postion\n2 Delete  specific value\n3 traverse linkdlist\n4 exit\n enter ur choice");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
       printf("Enter Value  ");
       scanf("%d",&b);
       InsertPost(&Start,b);
        break;
     
     case 2:
       
       printf("Your 1st is node is deleted\n ");
       scanf("%d",&c);
        deleteNode(&Start,c);
        break;
   
      case 3:
       traverFRbeg(Start);
        break;
    
       default:
        printf("your input is not in menu");
        break;
    }
    } while (choice!=4);
  
    return 0;
}