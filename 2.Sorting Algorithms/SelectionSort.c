#include <stdio.h>

void selectionSort(int arr[], int size) {
    for(int i = 0; i<size - 1; i++){
        int min = i;
        for(int j = i+1; j< size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int tempt = arr[i];
        arr[i] = arr[min];
        arr[min] = tempt;   
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, N);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}