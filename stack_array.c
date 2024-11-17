#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void push(int stack[], int *top, int data) {
    if (*top == SIZE - 1) {
        printf("\nOverflow\n");
    } else {
        stack[++(*top)] = data;
        printf("\nStack: ");
        for (int i = *top; i >= 0; i--) 
            printf("%d%s", stack[i], i == *top ? " <--- Top\n" : "\n");
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nUnderflow\n");
    } else {
        printf("\nPopped: %d", stack[(*top)--]);
        if (*top == -1) printf("\nStack is now empty\n");
        else {
            printf("\nStack: ");
            for (int i = *top; i >= 0; i--) 
                printf("%d%s", stack[i], i == *top ? " <--- Top\n" : "\n");
        }
    }
}

void status(int stack[], int *top) {
    float free_space = ((SIZE - (*top + 1)) * 100.0) / SIZE;
    if (*top == -1) printf("\nStack is empty\nFree space: 100%%\n");
    else if (*top == SIZE - 1) printf("\nStack is full\nFree space: 0%%\nTop: %d\n", stack[*top]);
    else printf("\nStack not full\nFree space: %.2f%%\nTop: %d\n", free_space, stack[*top]);
}

int main() {
    int stack[SIZE], top = -1, choice, data;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Status\n4.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter data: "); scanf("%d", &data); push(stack, &top, data); }
        else if (choice == 2) pop(stack, &top);
        else if (choice == 3) status(stack, &top);
        else if (choice == 4) exit(0);
        else printf("\nInvalid choice\n");
    }
    return 0;
}
