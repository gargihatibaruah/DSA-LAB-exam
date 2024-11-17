#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (rear) rear->next = newnode;
    rear = newnode;
    if (!front) front = newnode;
}

void dequeue() {
    if (!front) printf("Underflow\n");
    else {
        struct node *temp = front;
        printf("Dequeued: %d\n", temp->data);
        front = front->next;
        if (!front) rear = NULL;
        free(temp);
    }
}

void display() {
    if (!front) printf("Queue is empty\n");
    else {
        struct node *temp = front;
        printf("Queue: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter value: "); scanf("%d", &value); enqueue(value); }
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}
