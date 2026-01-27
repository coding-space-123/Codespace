#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
} NODE;

/* ---- FUNCTION DECLARATIONS ---- */
NODE* createNode(int data);
NODE* insert(NODE *root, int data);
NODE* del_nrec(NODE *root, int dkey);

NODE* case_a(NODE *root, NODE *par, NODE *ptr);
NODE* case_b(NODE *root, NODE *par, NODE *ptr);
NODE* case_c(NODE *root, NODE *par, NODE *ptr);

void inorder(NODE *root);

/* ------------------ MAIN FUNCTION ------------------ */
int main() {
    NODE *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    root = del_nrec(root, 50); // deleting root

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

/* ------------------ CREATE NEW NODE ------------------ */
NODE* createNode(int data) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

/* ------------------ INSERT FUNCTION ------------------ */
NODE* insert(NODE *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->info)
        root->lchild = insert(root->lchild, data);
    else
        root->rchild = insert(root->rchild, data);

    return root;
}

/* ------------------ NON-RECURSIVE DELETE ------------------ */
NODE* del_nrec(NODE *root, int dkey) {
    NODE *par, *ptr;
    ptr = root;
    par = NULL;

    while (ptr != NULL) {
        if (dkey == ptr->info)
            break;
        par = ptr;

        if (dkey < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    if (ptr == NULL)
        printf("Key not found\n");
    else if (ptr->lchild != NULL && ptr->rchild != NULL)
        root = case_c(root, par, ptr);
    else if (ptr->lchild != NULL)
        root = case_b(root, par, ptr);
    else if (ptr->rchild != NULL)
        root = case_b(root, par, ptr);
    else
        root = case_a(root, par, ptr);

    return root;
}

/* ------------------ CASE A: NO CHILD ------------------ */
NODE* case_a(NODE *root, NODE *par, NODE *ptr) {
    if (par == NULL)      // deleting root
        root = NULL;
    else if (ptr == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;

    free(ptr);
    return root;
}

/* ------------------ CASE B: ONE CHILD ------------------ */
NODE* case_b(NODE *root, NODE *par, NODE *ptr) {
    NODE *child;

    if (ptr->lchild != NULL)
        child = ptr->lchild;
    else
        child = ptr->rchild;

    if (par == NULL)          // deleting root
        root = child;
    else if (ptr == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;

    free(ptr);
    return root;
}

/* ------------------ CASE C: TWO CHILDREN ------------------ */
NODE* case_c(NODE *root, NODE *par, NODE *ptr) {
    NODE *succ, *parsucc;

    parsucc = ptr;
    succ = ptr->rchild;

    while (succ->lchild != NULL) {
        parsucc = succ;
        succ = succ->lchild;
    }

    ptr->info = succ->info;

    if (succ->lchild == NULL && succ->rchild == NULL)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);

    return root;
}


void inorder(NODE *root) {
    if (root == NULL)
        return;

    inorder(root->lchild);
    printf("%d ", root->info);
    inorder(root->rchild);
}
