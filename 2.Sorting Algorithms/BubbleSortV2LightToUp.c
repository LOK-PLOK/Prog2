#include <stdio.h>

void bubbleSortLightToUp(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = size - 1; j > i; j--) {
            if(arr[j] < arr[j - 1]) {   // Compare in reverse order for lighter elements
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
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
    bubbleSortLightToUp(arr, N);
    printf("Sorted array (light elements to top): ");
    printArray(arr, N);
    return 0;
}