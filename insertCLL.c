#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *tail = NULL;

void display_list() {
    if (!tail) { 
        printf("List is empty.\n"); 
        return; 
    }
    struct node *ptr = tail->next;
    printf("The list is: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
}

void insert_node(int data, int pos) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) { 
        printf("Insufficient memory...\n"); 
        return; 
    }
    newnode->data = data;

    if (!tail) { // Case: Empty list
        tail = newnode;
        newnode->next = tail;
    } else if (pos == 1) { // Insert at beginning
        newnode->next = tail->next;
        tail->next = newnode;
    } else { // Insert at a specific position or end
        struct node *temp = tail->next;
        for (int i = 1; i < pos - 1 && temp != tail; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp == tail) { // Insert at end
            tail = newnode;
        }
    }
    display_list();
}

void create_list() {
    int choice = 1;
    printf("Creating Circular Linked List...\n");
    while (choice) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        insert_node(data, 0x7FFFFFFF); // Insert at end
        printf("Add another node? (0 for No, 1 for Yes): ");
        scanf("%d", &choice);
    }
    display_list();
}

int main() {
    int user_input, pos, data;
    create_list();

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Exit\nChoice: ");
        scanf("%d", &user_input);
        if (user_input == 4) break;

        printf("Enter data to insert: ");
        scanf("%d", &data);

        pos = (user_input == 1) ? 1 : (user_input == 2 ? 0x7FFFFFFF : -1);
        if (user_input == 3 && pos == -1) { 
            printf("Enter position: "); 
            scanf("%d", &pos); 
        }
        insert_node(data, pos);
    }
    return 0;
}
