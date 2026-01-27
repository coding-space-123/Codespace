#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node* createNode(int v);
void insertFront(node **front, node **rear, int v);
void insertRear(node **front, node **rear, int v);
void deleteFront(node **front, node **rear);
void deleteRear(node **front, node **rear);
void display(node *front);

int main() {
    node *front = NULL, *rear = NULL;
    int ch, v;

    do {
        printf("\n*** MENU OF DEQUE OPERATIONS ***\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &v);
                insertFront(&front, &rear, v);
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &v);
                insertRear(&front, &rear, v);
                break;

            case 3:
                deleteFront(&front, &rear);
                break;

            case 4:
                deleteRear(&front, &rear);
                break;

            case 5:
                display(front);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

node* createNode(int v) {
    node *nn = (node*)malloc(sizeof(node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    nn->data = v;
    nn->prev = nn->next = NULL;
    return nn;
}

void insertFront(node **front, node **rear, int v) {
    node *nn = createNode(v);
    if (*front == NULL) {         // empty deque
        *front = *rear = nn;
    } else {
        nn->next = *front;
        (*front)->prev = nn;
        *front = nn;
    }
    printf("Inserted %d at front\n", v);
}

void insertRear(node **front, node **rear, int v) {
    node *nn = createNode(v);
    if (*rear == NULL) {          // empty deque
        *front = *rear = nn;
    } else {
        (*rear)->next = nn;
        nn->prev = *rear;
        *rear = nn;
    }
    printf("Inserted %d at rear\n", v);
}

void deleteFront(node **front, node **rear) {
    if (*front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    node *temp = *front;
    int v = temp->data;

    if (*front == *rear) {    // only one element
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
        (*front)->prev = NULL;
    }

    printf("Deleted %d from front\n", v);
    free(temp);
}

void deleteRear(node **front, node **rear) {
    if (*rear == NULL) {
        printf("Deque is empty\n");
        return;
    }

    node *temp = *rear;
    int v = temp->data;

    if (*front == *rear) {    // only one element
        *front = *rear = NULL;
    } else {
        *rear = (*rear)->prev;
        (*rear)->next = NULL;
    }

    printf("Deleted %d from rear\n", v);
    free(temp);
}

void display(node *front) {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}
