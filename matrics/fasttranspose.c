#include<stdio.h>
int reaarr(int arr[][3]){
    int c,r, n;
    printf("Enter the number coloum");
    scanf("%d",&c);
    printf("Enter the number row");
    scanf("%d",&r);

    printf("Enter the number element");
    scanf("%d",&n);
    arr[0][0]=r;
    arr[0][1]=c;
    arr[0][2]=n;
    for(int i=0;i<n;i++){
        printf("Enter row ,coloum,value on term %d",i);
        scanf("%d %d %d ",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    return n;
}

void printt(int arr[][3],int n){
    for(int i=0;i<n;i++){
        printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
    }
}

void fasttranspose(int A[][3],int B[][3]){
    int m,n,t;
    m=A[0][0];
    n=A[0][1];
    t=A[0][2];
    B[0][0]=n;
    B[0][1]=m;
    B[0][2]=t;
    if(t<0){
        return ;
    }
    int c[n],s[n];
    for(int i=1;i<n;i++){
        c[i]=0;
    }
   for(int i=1;i<=t;i++){
    c[A[i][1]]=c[A[i][1]]+1;
   }
   s[0]=1;
   for(int i=2;i<n;i++){
    s[i]=s[i-1]+c[i-1];
    
   }
   for (int i=1;i<t;i++){
    int j=A[i][1];
    B[s[j]][0]=A[i][1];
    B[s[j]][1]=A[i][0];
    B[s[j]][2]=A[i][2];
    s[j]=s[j]+1;
   }
}
int main()
{
int nterms;
    int arr[50][3];
    int b[50][3];

    nterms = reaarr(arr);
    printf("\nMatrix before fast_transpose:\n");
    printt(arr, nterms);

    fasttranspose(arr, b);
    printf("\nMatrix after fast_transpose:\n");
    printt(b, nterms);

    return 0;
}