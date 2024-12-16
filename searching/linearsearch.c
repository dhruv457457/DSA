#include<stdio.h>
#define MAX (10)

int linearsearch(int arr[],int element){
    for(int i=0;i<MAX;i++){
        if(arr[i]==element){
            return i;
        }
    
    }
    return -1;
}
int main(){
    int arr[10]={1,2,1,4,52,3,4,2,23};
    
    
    int res=linearsearch(arr,3);
    printf("Key found at %d",res);
    return 0;

}