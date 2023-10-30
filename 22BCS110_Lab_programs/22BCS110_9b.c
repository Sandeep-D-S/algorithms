#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int swapped = 0;
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
}
void printArray(int arr[], int size){
    for(int i = 0;i<size;i++){
        printf("\n%d",arr[i]);
    }
}
int main(){
    int arr[5] = {100,20,3,45,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
}