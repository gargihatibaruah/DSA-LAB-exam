#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};
struct node *header = NULL;

void display_list() {
    struct node *ptr = header;
    printf("List: ");
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete_node(int pos) {
    if (!header) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = header;

    if (pos == 1) { // Delete at beginning
        header = header->next;
        if (header) header->prev = NULL;
        free(temp);
    } else {
        int i = 1;
        struct node *prev = NULL;
        while (temp && (pos == 0x7FFFFFFF ? temp->next : i < pos)) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (!temp) {
            printf("Position out of range.\n");
            return;
        }

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        else header = temp->next;  // Special case when deleting the first node
        free(temp);
    }
    display_list();
}

void create_list() {
    int data, choice = 1;
    struct node *tail = NULL;

    while (choice) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;

        if (!header) header = tail = newnode;
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Add another? (0-No, 1-Yes): ");
        scanf("%d", &choice);
    }
    display_list();
}

int main() {
    int user_input, pos;

    create_list();

    while (1) {
        printf("\n1. Delete at beginning\n2. Delete at end\n3. Delete at position\n4. Exit\nChoice: ");
        scanf("%d", &user_input);
        if (user_input == 4) break;
        pos = (user_input == 1) ? 1 : (user_input == 2) ? 0x7FFFFFFF : 0;
        if (user_input == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
        }
        delete_node(pos);
    }
    return 0;
}