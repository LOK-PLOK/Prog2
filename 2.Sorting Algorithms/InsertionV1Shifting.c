#include <stdio.h>

void insertionSortShift(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int flag = arr[i];
        int j;
        for(j = i; j > 0 && flag < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = flag;
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
    insertionSortShift(arr, N);
    printf("Sorted array: ");
    printArray(arr, N);
    return 0;
}