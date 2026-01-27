#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* createnode(int v);
void enque(node **f, node **r, int v);
void deque(node **f, node **r);
void display(node *f);

int main() {
    node *f = NULL, *r = NULL;
    int ch, v;

    do {
        printf("\n*** MENU OF QUEUE OPERATION ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &v);
                enque(&f, &r, v);
                break;

            case 2:
                deque(&f, &r);
                break;

            case 3:
                display(f);
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
        return NULL;
    }
    nn->data = v;
    nn->next = NULL;
    return nn;
}

void enque(node **f, node **r, int v) {
    node *nn = createnode(v);

    if (*r == NULL) {        // empty queue
        *f = *r = nn;
    } else {
        (*r)->next = nn;
        *r = nn;
    }
    printf("Enque value = %d\n", v);
}

void deque(node **f, node **r) {
    int v;
    if (*f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    if(*f==*r)
    {
        *r=NULL;
    }
    node *temp=*f;
    *f=(*f)->next;
    v=temp->data;
    printf("Deque value = %d\n", v);
    free(temp);
}

void display(node *f) {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elsements are : ");
    while (f != NULL) {
        printf("%d\t ", f->data);
        f = f->next;
    }
    
}
