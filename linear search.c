#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) { // Check if current element matches the key
            return i; // Return the index of the matching element
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function to display the array
void displayArray(int array[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to get input for the array
void inputArray(int array[], int size) {
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Main function
int main() {
    int size, key, result;

    // Ask user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if size is valid
    if (size <= 0) {
        printf("Invalid size. Exiting program.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Input elements into the array
    inputArray(array, size);

    // Display the array
    displayArray(array, size);

    // Ask user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Perform linear search
    result = linearSearch(array, size, key);

    // Display the result
    if (result != -1) {
        printf("Key %d found at index %d.\n", key, result);
    } else {
        printf("Key %d not found in the array.\n", key);
    }

    // Free the dynamically allocated memory
    free(array);

    return 0;
}