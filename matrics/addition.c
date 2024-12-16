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
void add_matrics(int mat1[][3],int mat2[][3],int mat3[][3]){
    int t1,t2;
    int i,j,k;
    i=j=k=1;
    t1=mat1[0][3];
    t2=mat2[0][3];
    while (i<=t1&&j<=t2)
    {
        if(mat1[i][0]<mat2[j][0]){
            mat3[k][0]=mat1[i][0];
            mat3[k][1]=mat1[i][1];
            mat3[k][2]=mat1[i][2];
            i++;
            j++;
        }
        else if(mat1[i][0]>mat2[j][0]){
            mat3[k][0]=mat2[j][0];
            mat3[k][1]=mat2[j][1];
            mat3[k][2]=mat2[j][2];
            j++,k++;
        }
        else    if(mat1[i][1]<mat2[j][1]){
            mat3[k][0]=mat1[i][0];
            mat3[k][1]=mat1[i][1];
            mat3[k][2]=mat1[i][2];
            i++;
            j++;
        }
        else if(mat1[i][1]>mat2[j][1]){
            mat3[k][0]=mat2[j][0];
            mat3[k][1]=mat2[j][1];
            mat3[k][2]=mat2[j][2];
            j++,k++;
        }
        else{
            mat3[k][0]=mat2[j][0];
            mat3[k][1]=mat2[j][1];
            mat3[k][2]=mat1[i][2]+mat2[j][2];
            i++,j++,k++;
        }
    }
    while(i<=t1){
        mat3[k][0]=mat1[i][0];
        mat3[k][1]=mat1[i][1];
        mat3[k][2]=mat1[i][2];
        i++,k++;
    }
    while(j<=t2){
        mat3[k][0]=mat1[j][0];
        mat3[k][1]=mat1[j][1];
        mat3[k][2]=mat1[j][2];
        j++,k++;
    }
    mat3[0][3]=k-1;
    mat3[0][1]=mat1[0][1];
    mat3[0][2]=mat2[0][2];
    
}
int main(){
    int arr1[3][3],arr2[3][3],arr3[3][3];
    int n1=reaarr(arr1);
    int n2=reaarr(arr2);
    
    printf("mat 1\n");
    printt(arr1, n1);
    printf("mat 2\n");
    printt(arr2, n2);
    printf("Addition \n");
    add_matrics(arr1,arr2,arr3);
    printt(arr3,n2);
    return 0;


}