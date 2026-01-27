#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* createnode(int v);
node *enque(node *tail, int v);
node *deque(node *tail);
void display(node *tail);

int main() {
    node *tail = NULL;
    int ch, v;
    printf("\n*** MENU OF QUEUE OPERATION ***\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");  
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &v);
                tail = enque(tail, v);
                break;

            case 2:
                tail = deque(tail);
                break;

            case 3:
                display(tail);
                break;

            case 4:
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
        printf("Memory allocation failed\n");
        exit(1);
    }
    nn->data = v;
    nn->next = NULL;
    return nn;
}

node *enque(node *tail, int v) {
    node *nn = createnode(v);

    if (tail == NULL) {
        nn->next = nn;   // first node
        tail = nn;
    } else {
        nn->next = tail->next;
        tail->next = nn;
        tail = nn;
    }
    printf("Enqueue value = %d\n", v);
    return tail;
}

node *deque(node *tail) {
    if (tail == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    node *head = tail->next;
    if (head == tail) {
        printf("Deque value = %d\n", head->data);
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next;
        printf("Deque value = %d\n", head->data);
        free(head);
    }
    return tail;
}

void display(node *tail) {
    if (tail == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *p = tail->next;
    printf("Queue elements are: ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}
