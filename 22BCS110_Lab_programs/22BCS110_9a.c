#include<stdio.h>
void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
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
    insertionSort(arr, size);
    printArray(arr, size);
}