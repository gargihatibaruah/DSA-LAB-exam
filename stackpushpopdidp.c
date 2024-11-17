#include <stdio.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        s->items[++(s->top)] = item;
        printf("%d pushed to stack.\n", item);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    pop(&s);
    display(&s);
    
    return 0;
}
