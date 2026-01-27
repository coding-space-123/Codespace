#include <stdio.h>
#include <stdlib.h>

#define SIZE 3


typedef struct {
    int arr[SIZE];
    int front, rear;
} Deque;

void deleteRear(Deque *dq) ;
void display(Deque *dq);
int isEmpty(Deque dq) ;
int isFull(Deque dq);
void insertRear(Deque *dq, int v);
void display(Deque *dq);
void deleteFront(Deque *dq);
void insertFront(Deque *dq, int v) ;

int main() {
    Deque dq;
    dq.front = dq.rear = -1;
    int choice, val;

    printf("\n*** MENU OF DOUBLE ENDED QUEUE (LINEAR) ***\n\n");
    printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(&dq, val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(&dq, val);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
        }
    } while (1);

    return 0;
}

int isFull(Deque dq) {
    return (dq.rear == SIZE - 1);  
}

int isEmpty(Deque dq) 
{
    return (dq.front == -1);
}

void insertFront(Deque *dq, int v) 
{
    if (isFull(*dq)) {
        printf("Deque is full\n");
        return;
}
    if (dq->front == -1) 
	{ 
    
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {  
        printf("No space at front (Linear Queue restriction)\n");
        return;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = v;
}

void insertRear(Deque *dq, int v) {
    if (isFull(*dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->rear == -1) { 
        dq->front = dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = v;
}

void deleteFront(Deque *dq) {
    if (isEmpty(*dq)) {
        printf("Deque is empty\n");
        return;
    }
    int removed = dq->arr[dq->front];
    printf("Deleted %d from front\n", removed);

    if (dq->front == dq->rear) 
        dq->front = dq->rear = -1;
    else
        dq->front++;
}

void deleteRear(Deque *dq) 
{
    if (isEmpty(*dq)) {
        printf("Deque is empty\n");
        return;
    }
    int removed = dq->arr[dq->rear];
    printf("Deleted %d from rear\n", removed);

    if (dq->front == dq->rear)  
        dq->front = dq->rear = -1;
    else
        dq->rear--;
}

void display(Deque *dq) {
	int i;
    if (isEmpty(*dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    for ( i = dq->front; i <= dq->rear; i++) {
        printf("%d ", dq->arr[i]);
    }
    printf("\n");
}



