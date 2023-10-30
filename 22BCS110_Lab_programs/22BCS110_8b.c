#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
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
    selectionSort(arr, size);
    printArray(arr, size);
}