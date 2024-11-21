#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int array[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == key) return mid;
        else if (array[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Function to sort the array (bubble sort)
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

int main() {
    int size, key, result;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Input elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) scanf("%d", &array[i]);

    // Sort the array
    bubbleSort(array, size);

    // Input key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Perform binary search
    result = binarySearch(array, size, key);

    // Output result
    if (result != -1)
        printf("Key %d found at index %d.\n", key, result);
    else
        printf("Key %d not found.\n", key);

    free(array); // Free allocated memory
    return 0;
}