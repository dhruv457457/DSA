#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heapSort(int arr[], int n);
void buildMaxHeap(int arr[], int n);
void maxHeapify(int arr[], int n, int i);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void radixSort(int arr[], int n);
int getMax(int arr[], int n);
void countingSortForRadix(int arr[], int n, int exp);
void countingSort(int arr[], int n, int range);
void printArray(int arr[], int n);

int main() {
    int choice, n, i;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Heap Sort\n");
        printf("6. Merge Sort\n");
        printf("7. Radix Sort\n");
        printf("8. Counting Sort\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                break;
            case 4:
                quickSort(arr, 0, n - 1);
                break;
            case 5:
                heapSort(arr, n);
                break;
            case 6:
                mergeSort(arr, 0, n - 1);
                break;
            case 7:
                radixSort(arr, n);
                break;
            case 8:
                countingSort(arr, n, 100); 
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("Sorted array: ");
        printArray(arr, n);

    } while (choice != 9);

    return 0;
}
void bubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while (j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
}
void selectionSort(int arr[], int n){
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low-1;
    int j=high;
    while (i <= high && arr[i] <= pivot) {
            i++;
        }
    while (j >= low && arr[j] >= pivot) {
            i--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        int temp=arr[j];
        arr[j]=arr[low];
        arr[low]=temp;
    return j;
    }
void quickSort(int arr[], int low, int high){
     if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapSort(int arr[], int n){
    
}
