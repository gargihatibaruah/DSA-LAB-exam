#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *header = NULL;

void display_list() {
    struct node *ptr = header;
    int count = 0;
    printf("The list is: ");
    while (ptr) {
        printf("%d(%d) ", ptr->data, ++count);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete_node(int pos) {
    if (!header) { printf("List is empty.\n"); return; }
    struct node *temp = header;

    if (pos == 1) {  // Delete at beginning
        header = header->next;
        if (header) header->prev = NULL;
        free(temp);
    } else {
        for (int i = 1; temp && i < pos; i++) temp = temp->next;
        if (!temp) { printf("Position out of range.\n"); return; }
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        free(temp);
    }
    display_list();
}

void create_list() {
    int data, choice = 1;
    struct node *tail = NULL;
    printf("Creating Doubly Linked List...\n");
    while (choice) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (!newnode) { printf("Insufficient memory...\n"); return; }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;
        if (!header) header = tail = newnode;
        else {
            tail->next = newnode;
            newnode->prev = tail;
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
