#include<stdio.h>

#define Max 10
struct stack
{
    int top;
    int stack[Max];
};
typedef struct stack st;
void createstack(st *ps)
{
    ps->top=-1;

}
int isempty( st *ps){
    if(ps->top==-1){
    return 1;}
    else{
        return 0;
    }
}
int isfull(st *ps){
    if(ps->top==(Max-1)){
    return 1;}
    else{ 
       return 0;}
}


void push(st *ps ,int val){
    if(ps->top==Max-1){
        printf("stack is full");
        return;
    }
    ps->top++;
    ps->stack[ps->top]=val;

}

void pop(st *ps){
    int temp;
    if(ps->top==-1){
        printf("Stack isEmpty");
        return;

    }
    temp=ps->stack[ps->top];
    printf("Popped element: %d\n", temp);
    ps->top--;

}
void show(st *ps) {
    if (isempty(ps)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = ps->top; i >= 0; i--) {
        printf("%d\n", ps->stack[i]);
    }
}
void peep(st *ps,int postion){
    if(postion <1||postion>ps->top+1){
        printf("Value not found");
        return;
    }
    printf("Element o poston %d is %d",postion,ps->stack[ps->top-postion+1]);
}

int main (){
    st s;
    createstack(&s);
        
    int num, ch;
    do{
        printf("\n Enter your choice\n1 push\n2 pop\n3 show\n0 exit");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
    
            printf("enter ur number");
            scanf("%d",&num);
            push(&s,num);
            
            break;
         case 2:
            pop(&s);
            break;
         case 3:
            show(&s);
            break;
         case 4:
            printf("enter on what Postion u waant to peep ");
            scanf("%d",&num);
            peep(&s,num);
            break;
         case 0:
            exit(0);


        
        default:
            printf("Invalid input");
            break;
        }
    }while(1);
}