#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* createnode(int v);
void displaylist(node *start);
node* removeDuplicatesSorted(node *start);
node* priorityInsert(node *start, int value);
node* sortedlist(node *start);
void searchNode(node *start, int key);   // 🔍 Function prototype

int main() {
    int ch, value;
    node *start = NULL;

    printf("\n*** MENU OF LINKED LIST INSERTION ***\n");
    printf("1. Insert in sorted order\n");
    printf("2. Display list\n");
    printf("3. Priority Queue Insert\n");
    printf("4. Remove Duplicates (Sorted)\n");
    printf("5. Search Element\n");
    printf("6. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                start = sortedlist(start);
                break;

            case 2:
                displaylist(start);
                break;

            case 3: 
                printf("Enter value: ");
                scanf("%d", &value);
                start = priorityInsert(start, value);
                displaylist(start);
                break;

            case 4: 
                start = removeDuplicatesSorted(start);
                displaylist(start);
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(start, value);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

node* createnode(int v) {
    node *nn = (node*)malloc(sizeof(node));
    if (nn == NULL) {
        printf("Memory overflow or error\n");
        return NULL;
    }
    nn->data = v;
    nn->next = NULL;
    return nn;
}

void displaylist(node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    node *p = start;
    printf("List: ");
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;  
    }
    printf("\n");
}

node* sortedlist(node *start) {
    int v;
    char ch;
    node *nn, *p;

    do {
        printf("Enter the value: ");
        scanf("%d", &v);
        nn = createnode(v);

        if (start == NULL || nn->data < start->data) {
            nn->next = start;
            start = nn;
        } else {
            p = start;
            while (p->next != NULL && p->next->data <= nn->data)
                p = p->next;
            nn->next = p->next;
            p->next = nn;
        }

        printf("Do you want to add more nodes (y/n): ");
        scanf(" %c", &ch);  
    } while (ch == 'y' || ch == 'Y');

    return start;
}

node* priorityInsert(node *start, int value) {
    node *nn = createnode(value);

    if (start == NULL || value < start->data) {
        nn->next = start;
        start = nn;
    } else {
        node *p = start;
        while (p->next != NULL && p->next->data <= value)
            p = p->next;
        nn->next = p->next;
        p->next = nn;
    }
    return start;
}

node* removeDuplicatesSorted(node *start) {
    if (start == NULL)
        return start;

    node *curr = start;
    node *temp;

    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return start;
}

// 🔍 Search function
void searchNode(node *start, int key) {
    int pos = 1;
    node *p = start;

    while (p != NULL) {
        if (p->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        p = p->next;
        pos++;
    }

    printf("Element %d not found in the list.\n", key);
}
