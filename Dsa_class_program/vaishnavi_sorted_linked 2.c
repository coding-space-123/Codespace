#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* createnode(int v);
void displaylist(node *start);
node* deletion(node *start);
node* sortedlist(node *start);
void rev_dis(node *start);
node* rev_list(node *start);

int main() {
    int ch;
    node *start = NULL;

    do {
        printf("\n*** MENU OF LINKED LIST ***\n");
        printf("1. Insert in sorted order\n2. Delete by value\n3. Display\n4.display reverse list\n5.reverse linked_list\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                start = sortedlist(start);
                break;
            case 2:
                start = deletion(start);
                break;
            case 3:
                displaylist(start);
                break;
            case 4:
                rev_dis(start);
                break;
            case 5:
                start=rev_list(start);
                displaylist(start);
                break;  
            case 6:
                printf("Exiting...\n");
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

node* deletion(node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    int target;
    printf("Enter the value to be deleted: ");
    scanf("%d", &target);

    node *temp, *p;

    if (start->data == target) {
        temp = start;
        start = start->next;
        printf("Deleted %d\n", target);
        free(temp);
        return start;
    }

    p = start;
    while (p->next != NULL && p->next->data != target)
        p = p->next;

    if (p->next != NULL) {
        temp = p->next;
        p->next = p->next->next;
        printf("Deleted %d\n", target);
        free(temp);
    } else {
        printf("Value not found\n");
    }

    return start;
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

void rev_dis(node *start)
{
    node *p =start;
    if(p==NULL)
        return;
    rev_dis(p->next);
    printf("%d\t",p->data);

}

node* rev_list(node *start)
{
    node *p=NULL,*c=start,*n;
    while(c != NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}