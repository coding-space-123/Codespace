#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct stack
{
    int top;
    int arr[SIZE];
} Stack;


typedef struct queue
{
    Stack stack1, stack2;
    int count;
} Queue;


void push(Stack *s, int val) ;
int isEmpty(Stack s);
int pop(Stack *s) ;

void enqueue(Queue *q, int val);
int dequeue(Queue *q) ;
void display(Queue q);


int main() {
    Queue q;
    q.stack1.top = -1;
    q.stack2.top = -1;
    q.count = 0;

    int choice, val,poped;
    printf("\n***MENU OF QUEUE OPERATION***\n");
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4.exit\n");
	printf("\nenter choice which operation want to perform:");
    do
	{
		printf("\nenter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                	printf("Enter value to enqueue: ");
                	scanf("%d", &val);
                	enqueue(&q, val);
                	
                	break;
            case 2:
                	poped=dequeue(&q);
                	if(poped!=-999)
                		printf("Dequeued element: %d\n",poped);
                	
                	break;
            case 3:
                	display(q);
                	break;
            case 4:
                	exit(0);
            default:
                	printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}


void push(Stack *s, int val) 
{
    if (s->top == SIZE - 1) 
	{
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
    
}

int pop(Stack *s) 
{
    if (s->top == -1) 
	{
        printf("Stack Underflow!\n");
        return -999 ;
    }
    return s->arr[s->top--];
}

int isEmpty(Stack s) {
    return s.top == -1;
}


void enqueue(Queue *q, int val) {
    if (q->stack1.top == SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    push(&q->stack1, val);
    q->count++;
}

int dequeue(Queue *q) {
    int popped;

    if (isEmpty(q->stack1) && isEmpty(q->stack2)) {
        printf("Queue is empty!\n");
        return -999;
    }

    if (isEmpty(q->stack2)) {
        while (!isEmpty(q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }

    popped = pop(&q->stack2);
    q->count--;
    return popped;
}


void display(Queue q) 
{
    int i;

    if (isEmpty(q.stack1) && isEmpty(q.stack2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    
    for (i = q.stack2.top; i >= 0; i--) {
        printf("%d ", q.stack2.arr[i]);
    }

    for (i = 0; i <= q.stack1.top; i++) {
        printf("%d ", q.stack1.arr[i]);
    }

    printf("\n");
}



