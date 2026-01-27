#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Create a new node
Node* createNode(int value) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = value;
    nn->next = nn->prev = NULL;
    return nn;
}

// Insert at REAR only
void insertRear(Node **front, Node **rear, int value) {
    Node *nn = createNode(value);
    if (*rear == NULL) {  // First element
        *front = *rear = nn;
    } else {
        (*rear)->next = nn;
        nn->prev = *rear;
        *rear = nn;
    }
    printf("Inserted %d at rear.\n", value);
}

// Delete from FRONT
void deleteFront(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Deque is empty. Deletion not possible.\n");
        return;
    }
    Node *temp = *front;
    printf("Deleted %d from front.\n", temp->data);

    if (*front == *rear) {  // Only one element
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
        (*front)->prev = NULL;
    }
    free(temp);
}

// Delete from REAR
void deleteRear(Node **front, Node **rear) {
    if (*rear == NULL) {
        printf("Deque is empty. Deletion not possible.\n");
        return;
    }
    Node *temp = *rear;
    printf("Deleted %d from rear.\n", temp->data);

    if (*front == *rear) {  // Only one element
        *front = *rear = NULL;
    } else {
        *rear = (*rear)->prev;
        (*rear)->next = NULL;
    }
    free(temp);
}

// Display the deque
void display(Node *front) {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    Node *p = front;
    printf("Deque elements: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Main menu
int main() {
    Node *front = NULL;
    Node *rear = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Input Restricted Deque (Linked List) ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertRear(&front, &rear, value);
                break;
            case 2:
                deleteFront(&front, &rear);
                break;
            case 3:
                deleteRear(&front, &rear);
                break;
            case 4:
                display(front);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
