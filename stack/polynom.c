#include<stdio.h>
void polyadd(int arrA[],int arrB[],int arrC[])
{
    int m,n;
    n=0;
    m=0;
    m=arrA[0];
    n=arrB[0];
    int p,q,r;
    p=r=q=1;
    while (p<=2*m&&q<=2*n)
    {
        if(arrA[p]==arrB[q]){
            arrC[r] = arrA[p];
            arrC[r+1]=arrA[p+1]+arrB[q+1];
        if(arrC[r+1]!=0){
          
            r=r+2;
        }
        p=p+2;
        q=q+2;
            
        }
            
    else if (arrA[p]<arrB[q])
    {
        arrC[r+1]=arrB[q+1];
        arrC[r]=arrB[q];
        r=r+2;
        q=q+2;
    }
    else{
            arrC[r+1]=arrA[p+1];
            arrC[r]=arrA[p];
            r=r+2;
            p=p+2;

        
    }
    }
       while (p <= 2 * m) {
        arrC[r] = arrA[p];
        arrC[r + 1] = arrA[p + 1];
        p += 2;
        r += 2;
    }
        while (q <= 2 * n) {
        arrC[r] = arrB[q];
        arrC[r + 1] = arrB[q + 1];
        q += 2;
        r += 2;
    }


    arrC[0]=r/2 ;
}

void readpoly(int arr[]){
    printf("Enter number of digit\n");
    
    scanf("%d",&arr[0]);
    for (int i = 1; i <=(2*arr[0]); i=i+2)
    {
    printf("Enter coff\n");
    scanf("%d",&arr[i+1]);
    printf("Enter expo\n");
    scanf("%d",&arr[i]);
        
    }

}
void display(int arr[]){

    printf("\nResult ");
    for (int i=1; i <= 2*arr[0]; i=i+2) {
        printf("%d", arr[i+1]);
        if (arr[i] > 1) {
            printf("x^%d", arr[i]);
        } else if (arr[i]==1) {
            printf("x");
        }
        if (i < 2*arr[0]-1) {
            printf(" + ");
        }
    }
    printf("\n");
}
int main(){
    int arrA[100],arrC[100],arrB[100];
    printf("Enter data of A\n");
    readpoly(arrA);
    printf("Enter data of B\n");

    readpoly(arrB);
    polyadd(arrA,arrB,arrC);

    printf("output ye raa\n");
    display(arrA);
    display(arrB);
    display(arrC);
    polyadd(arrC,arrC,arrC);
    display(arrC);
    return 0;

}