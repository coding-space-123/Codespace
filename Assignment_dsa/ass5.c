#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int data[SIZE];
    int top[SIZE];
    int stackSize;
    int n;
} stack;

void initialize_stack(stack *s, int n);
int isfull(stack s, int id);
int isemptystack(stack s, int id);
void push(stack *s, int id, int val);
int pop(stack *s, int id);
void display(stack s, int id);

int main() {
    int choice, id, val, n;
    stack s;

    printf("Enter number of stacks (max %d): ", SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > SIZE) {
        printf("Invalid number of stacks.\n");
        return 1;
    }

    initialize_stack(&s, n);
    printf("\nInitialized Static Multi-Stack with %d stacks.\n", n);

    do {
        printf("\n--- MENU (STATIC) ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2 || choice == 3) {
            printf("Enter stack number (0 to %d): ", n - 1);
            scanf("%d", &id);
            if (id < 0 || id >= n) {
                printf("Invalid stack number.\n");
                continue;
            }
        }

        switch (choice) 
		{
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&s, id, val);
                break;
            case 2:
                val = pop(&s, id);
                if (val != -1)
                    printf("Popped value: %d\n", val);
                break;
            case 3:
                display(s, id);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void initialize_stack(stack *s, int n) 
{
	int i;
    s->n = n;
    s->stackSize = SIZE / n;
    for (i = 0; i < n; i++)
        s->top[i] = (i * s->stackSize) - 1;
}

int isfull(stack s, int id) {
    return s.top[id] == ((id + 1) * s.stackSize) - 1;
}

int isemptystack(stack s, int id) {
    return s.top[id] == (id * s.stackSize) - 1;
}

void push(stack *s, int id, int val) {
    if (isfull(*s, id)) {
        printf("Stack %d is Full.\n", id);
        return;
    }
    s->data[++s->top[id]] = val;
}

int pop(stack *s, int id) {
    if (isemptystack(*s, id)) {
        printf("Stack %d is Empty.\n", id);
        return -1;
    }
    return s->data[s->top[id]--];
}

void display(stack s, int id) 
{
	int i;
    if (isemptystack(s, id)) {
        printf("Stack %d is Empty.\n", id);
        return;
    }
    printf("Stack %d elements (top to bottom): ", id);
    for (i = s.top[id]; i >= id * s.stackSize; i--)
        printf("%d ", s.data[i]);
    printf("\n");
}

