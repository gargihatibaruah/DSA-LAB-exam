#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = 0, rear = -1, count = 0;

void enqueue(int val) {
    if (count == SIZE) printf("Overflow\n");
    else {
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
        count++;
    }
}

void dequeue() {
    if (count == 0) printf("Underflow\n");
    else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % SIZE;
        count--;
    }
}

void display() {
    if (count == 0) printf("Queue is empty\n");
    else {
        printf("Queue: ");
        for (int i = 0; i < count; i++) 
            printf("%d ", queue[(front + i) % SIZE]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter value: "); scanf("%d", &val); enqueue(val); }
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) break;
    }
    return 0;
}
