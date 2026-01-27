#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int c, e;
    struct Node *next;
} node;


node* createnode(int c, int e);
void display(node *start);
node* createpoly(node *start);
node* addpoly(node* poly1, node* poly2);

int main() {
    int ch, x, v;
    node *poly1 = NULL, *poly2 = NULL, *start = NULL;

    printf("\n*** MENU OF POLYNOMIAL ***\n");
    printf("1. createpoly\n2. display\n3. add\n4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("enter ist poly:\n");  
                poly1 = createpoly(poly1);
                printf("enter 2nd poly:\n");  
                poly2 = createpoly(poly2);
                break;

            case 2:
                printf("Polynomial 1: ");
                display(poly1);
                printf("Polynomial 2: ");
                display(poly2);
            //     if (start) {
            //         printf("Sum: ");
            //         display(start);
            //     }
                break;

            case 3:
                if (poly1 && poly2) {
                    start = addpoly(poly1, poly2);
                    printf("Polynomials added successfully.\n");
                    printf("Sum Polynomial: ");
                    display(start);
                } else {
                    printf("Addition not possible\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

node* createnode(int c, int e) {
    node *nn = (node*)malloc(sizeof(node));
    if (nn == NULL) {
        printf("Memory overflow or error\n");
        return NULL;
    }
    nn->c = c;
    nn->e = e;
    nn->next = NULL;
    return nn;
}

node* createpoly(node *start) {
    node *nn, *p;
    int c, e, n, i = 1;

    printf("Enter number of terms = ");
    scanf("%d", &n);
    printf("REMEMBER: polynomial is in high degree to low degree.\n");

    while (i <= n) {
        printf("Enter coefficient and exponent of term %d: ", i);
        scanf("%d%d", &c, &e);
        nn = createnode(c, e);

        if (start == NULL) {
            start = nn;
            p = start;
        } else {
            p->next = nn;
            p = nn;
        }
        i++;
    }
    return start;
}

node* addpoly(node *poly1, node *poly2) {
    int e, c;
    node *nn, *p1 = poly1, *p2 = poly2, *p3 = NULL, *poly3 = NULL;

    while (p1 && p2) {
        if (p1->e == p2->e) {
            e = p1->e;
            c = p1->c + p2->c;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->e > p2->e) {
            e = p1->e;
            c = p1->c;
            p1 = p1->next;
        } else {
            e = p2->e;
            c = p2->c;
            p2 = p2->next;
        }

        nn = createnode(c, e);
        if (!poly3) {
            poly3 = nn;
            p3 = poly3;
        } else {
            p3->next = nn;
            p3 = nn;
        }
    }

    while (p1) {
        nn = createnode(p1->c, p1->e);
        if (!poly3) {
            poly3 = nn;
            p3 = poly3;
        } else {
            p3->next = nn;
            p3 = nn;
        }
        p1 = p1->next;
    }

    while (p2) {
        nn = createnode(p2->c, p2->e);
        if (!poly3) {
            poly3 = nn;
            p3 = poly3;
        } else {
            p3->next = nn;
            p3 = nn;
        }
        p2 = p2->next;
    }

    return poly3;
}

void display(node *start) {
    node *p = start;

    if (start == NULL) {
        printf("Polynomial does not exist\n");
        return;
    }

    printf("polynomial expression: ");
    while (p) {
        if (p != start && p->c >= 0)
            printf("+");

        if (p->e == 0)
            printf("%d", p->c);
        else if (p->e == 1)
            printf("%dx", p->c);
        else
            printf("%dx^%d", p->c, p->e);

        p = p->next;
    }
    printf("\n");
}
