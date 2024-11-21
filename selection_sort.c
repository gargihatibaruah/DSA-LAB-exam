#include <stdio.h>
#include <stdlib.h>

// Function to perform selection sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[minIndex]) minIndex = j;
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Function to display the array
void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) return 1;

    int *array = (int *)malloc(size * sizeof(int));
    if (!array) return 1;

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) scanf("%d", &array[i]);

    selectionSort(array, size);
    displayArray(array, size);

    free(array);
    return 0;
}