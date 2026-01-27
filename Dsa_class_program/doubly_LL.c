#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next , *prev;
}node;

node* createnode(int v);
void displaylist(node *start);
node* deletion(node *start);
node* sortedlist(node *start);
void rev_dis(node *start);
node* rev_list(node *start);

int main() {
    int ch;
    node *start = NULL;

    printf("\n*** MENU OF DOUBLY LINKED LIST ***\n");
    printf("1. Insert in sorted order\n2. Delete by value\n3. Display\n4.display reverse list\n5.reverse linked_list\n6.Exit\n");
    do 
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
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
                if(start)
                {
                    printf("reverse list is:");
                    rev_dis(start);
                }
                else
                    printf("list does not exist\n");
                break;
            case 5:
                if(start)
                {
                    printf("after applying reverse linked list function:\n");
                    start=rev_list(start);
                    displaylist(start);
                }
                else
                    printf("list does not exist\n");
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

node* createnode(int v) 
{
    node *nn = (node*)malloc(sizeof(node));
    if (nn == NULL) 
    {
        printf("Memory overflow or error\n");
        return NULL;
    }
    nn->data = v;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void displaylist(node *start) 
{
    if (start == NULL) 
    {
        printf("List is not exist\n");
        return;
    }
    node *p = start;
    printf("original List: ");
    while (p != NULL) 
    {
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

    if (start->data == target) 
    {
        temp = start;
        start = start->next;
        // start->prev=NULL;
        printf("Deleted %d\n", target);
        free(temp);
        return start;
    }

    p = start;
    while (p->next != NULL && p->next->data != target)
        p = p->next;

    if (p->next != NULL) 
    {
        temp = p->next;
        p->next = p->next->next;
        if(temp->next!=NULL)
            temp->next->prev=p;
        printf("Deleted %d\n", target);
        free(temp);
    } 
    else 
        printf("Value not found\n");
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

        if (start == NULL || nn->data < start->data) 
        {
            nn->next = start;
            start = nn;
        } 
        else 
        {
            p = start;
            while (p->next != NULL && p->next->data <= nn->data)
                p = p->next;
            nn->next = p->next;
            p->next = nn;
            nn->prev=p;
            if(nn->next != NULL)
                  nn->next->prev=nn;
        }

        printf("Do you want to add more nodes (y/n): ");
        scanf(" %c", &ch);  
    } while (ch == 'y' || ch == 'Y');

    return start;
}

void rev_dis(node *start)
{
    if(start == NULL) {
        printf("List does not exist\n");
        return;
    }
    node *p = start;

    while(p->next != NULL)
        p = p->next;
    while(p != NULL) {
        printf("%d\t", p->data);
        p = p->prev;
    }
    printf("\n");
}


node* rev_list(node *start)
{
    node *temp = NULL;
    node *current = start;

    while (current != NULL)
    {

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        start = temp->prev;

    return start;
}
