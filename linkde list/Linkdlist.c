#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node*create(struct node*start,int n);
void traverse(struct node*start);
struct node*insert_beg(struct node*start,int val);
struct node*insert_end(struct node*start, int val);
struct node*insert_pos(struct node*start, int pos, int val);
struct node*delete_first(struct node*start);
struct node*delete_last(struct node*start);
struct node*delete_value(struct node*start, int val);
int count(struct node*start);
int main()
{
    struct node* start=NULL;
    int n, choice, val, pos;
    printf("Write number of nodes ");
    scanf("%d",&n);
    start = create(start,n);
    traverse(start);
   
     while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Deletion of a given value\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
        printf("enter the value to be inserted ");
        scanf("%d",&val);
        start = insert_beg(start,val);
        traverse(start);
        break;
        case 2:
        printf("enter the value to be inserted ");
        scanf("%d",&val);
        start = insert_end(start,val);
        traverse(start);
        break;
        case 3:
        printf("enter the value to be inserted ");
        scanf("%d",&val);
        printf("enter position for insertion ");
        scanf("%d",&pos);
        start = insert_pos(start,pos,val);
        traverse(start);
        break;
        case 4:
        printf("enter the node to be deleted ");
        start = delete_first(start);
        traverse(start);
        break;
        case 5:
        printf("enter the node to be deleted ");
        start = delete_last(start);
        traverse(start);
        break;
        case 6:
        printf("enter the value which you have to delete");
        scanf("%d",&val);
        start = delete_value(start,val);
        traverse(start);
        break;
      
        default:
        printf("choice not found");
        break;
    }
     }
}
struct node*create(struct node*start,int n)
{
    int i,v;
    struct node*p ,*q;
    if (n<=0)
    return NULL;
    else
    {
        p=(struct node*)malloc(sizeof(struct node));
        printf("enter the value ");
        scanf("%d",&v);
        p->data=v;
        p->next=NULL;
        start=p;
        for(i=2;i<=n;i++)
        {
            q=(struct node*)malloc(sizeof(struct node));
            printf("enter the value ");
            scanf("%d",&v);
            q->data=v;
            q->next=NULL;
            p->next=q;
            p=p->next;
        }
    }
    return start;
}
void traverse(struct node*start)
{
    struct node* p=start;
    printf("\n");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL");
}
struct node*insert_beg(struct node*start,int val)
{
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->data=val;
    p->next=start;
    start=p; 
    return start;
}
struct node*insert_end(struct node*start,int val)
{
    struct node*p=(struct node*)malloc(sizeof(struct node));
    struct node*q=(struct node*)malloc(sizeof(struct node));
    p->data=val;
    p->next=NULL;
    if(start==NULL)
    start=p;
    else
    {
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
    return start;
}
int count(struct node*start)
{
    struct node*p;
    int c;
    p=start;
    c=0;
    while(p!=NULL)
    {
        p=p->next;
        c=c+1;
    }
    return c;
}
struct node*insert_pos(struct node*start, int pos, int val)
{
    struct node*p = start;
   int n=count(start);
    int i;
    p=start;
     if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return start;
    }

    for(i=1;i<pos-1;i++)
    {
        p=p->next;
    }
     struct node*q=(struct node*)malloc(sizeof(struct node));
    q->data=val;
    q->next=p->next;
    p->next=q;
    return start;
}
struct node*delete_first(struct node*start)
{
    struct node*p;
    if(start==NULL)
    printf("empty list");
    else
    {
        p=start;
        start=start->next;
        free(p);
    }
    return start;
}
struct node*delete_last(struct node*start)
{
    struct node*p, *q;
    p=start;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    free(p);
    q->next=NULL;
    return start;
}
struct node*delete_value(struct node*start, int val)
{
   struct node*p, *q;
   p = start;
  if(p != NULL &&p->data == val){
  start = p->next;
  free(p);
  return start;
  }
  while(p->data!=val){
    q = p;
    p = p->next;
    }
    if(p==NULL){
        printf("Value not found ");
        return start;
    }
  q->next = p->next;
  free(p);
  //start=q;
  return start;
  }