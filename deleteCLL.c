#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *tail = NULL;

void display_list() {
    if (!tail) { printf("List is empty.\n"); return; }
    struct node *ptr = tail->next;
    int count = 0;
    printf("The list is: ");
    do {
        printf("%d(%d) ", ptr->data, ++count);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
}

void delete_node(int pos) {
    if (!tail) { printf("List is empty.\n"); return; }
    struct node *temp = tail->next;

    if (pos == 1) {  // Delete at beginning
        if (tail == tail->next) {  // Single node
            free(tail);
            tail = NULL;
        } else {
            tail->next = temp->next;
            free(temp);
        }
    } else {
        struct node *prev = tail;
        for (int i = 1; i < pos && temp != tail; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == tail && pos != 1) tail = prev;  // Update tail if deleting last node
        if (prev->next != tail->next) {  // Node found
            prev->next = temp->next;
            free(temp);
        } else {
            printf("Position out of range.\n");
            return;
        }
    }
    display_list();
}

void create_list() {
    int choice = 1, data;
    struct node *newnode;
    printf("Creating Circular Linked List...\n");
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (!newnode) { printf("Insufficient memory...\n"); return; }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (!tail) {
            tail = newnode;
            newnode->next = tail;
        } else {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Add another node? (0 for No, 1 for Yes): ");
        scanf("%d", &choice);
    }
    display_list();
}

int main() {
    int user_input, pos;

    create_list();  // Create the list with user input data

    while (1) {
        printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at position\n4. Exit\nChoice: ");
        scanf("%d", &user_input);
        if (user_input == 4) break;
        if (user_input == 1) pos = 1;
        else if (user_input == 2) pos = 0x7FFFFFFF; // Delete at end
        else if (user_input == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
        } else continue;
        delete_node(pos);
    }
    return 0;
}
