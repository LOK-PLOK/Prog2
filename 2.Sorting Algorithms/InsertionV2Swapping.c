#include <stdio.h>

void insertionSortSwap(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
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
    insertionSortSwap(arr, N);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}