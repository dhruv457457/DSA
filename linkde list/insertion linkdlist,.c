#include<stdio.h>
#include<stdlib.h>
 struct Node {
    int data;
    struct Node * next;

 };
 void linkd( struct Node *ptr ){
   while(ptr!= NULL){
      printf("Element %d \n",ptr->data);
      ptr=ptr->next;
   }
 }
 struct Node * insertionBeging( struct Node *head ,int data ){
    struct Node *ptr= ((struct Node *) malloc(sizeof(struct Node )));
    ptr->data=data;
    ptr->next=head;
    return ptr;
 }

 struct Node * insertionIndex( struct Node *head ,int data,int index ){
    struct Node *ptr=(struct Node *) malloc(sizeof(struct Node ));
    struct Node *p =head;
    int i =0;
    while (i!=index-1)
    {
      p=p->next;
      i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

    return head;

 }
 
 int main(){
    struct Node * Start;
    struct Node * first;
    struct Node * second;

 
   Start=((struct Node *) malloc(sizeof(struct Node)));
   first=((struct Node *) malloc(sizeof(struct Node)));
   second=((struct Node *) malloc(sizeof(struct Node)));

   Start->data=7;
   Start->next=first;
   first->data=34;
   first->next=second;
   second->data=343;
   second->next=NULL;

   linkd(Start);
   // Start=insertionBeging(Start,80);
   Start=insertionIndex(Start,1678,2);
   printf("\n\n\n\n\n");
   linkd(Start);
   
    return 0;
 }