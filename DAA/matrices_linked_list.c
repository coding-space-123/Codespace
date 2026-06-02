#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* -------- Node structure -------- */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* -------- Global visited -------- */
int visited[MAX];

/* -------- Create new node -------- */
Node* createNode(int v) {
    Node *nn = (Node*)malloc(sizeof(Node));
    if (nn == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    nn->data = v;
    nn->next = NULL;
    return nn;
}

/* -------- Insert at end -------- */
void insert_end(Node *adj[], int i, int v) {
    Node *nn = createNode(v);
    Node *temp;

    if (adj[i] == NULL) {
        adj[i] = nn;
    } else {
        temp = adj[i];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nn;
    }
}

/* -------- BFS -------- */
void BFS(Node *adj[], int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    Node *temp;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        start = queue[front++];
        printf("%d ", start);

        temp = adj[start];
        while (temp != NULL) {
            if (visited[temp->data] == 0) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

/* -------- BFT -------- */
void BFT(Node *adj[], int v) {
    int i;
    for (i = 0; i < v; i++) {
        if (visited[i] == 0)
            BFS(adj, i);
    }
}

/* -------- DFS -------- */
void DFS(Node *adj[], int v) {
    Node *temp;

    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];
    while (temp != NULL) {
        if (visited[temp->data] == 0)
            DFS(adj, temp->data);
        temp = temp->next;
    }
}

/* -------- DFT -------- */
void DFT(Node *adj[], int v) {
    int i;
    for (i = 0; i < v; i++) {
        if (visited[i] == 0)
            DFS(adj, i);
    }
}

/* -------- Reset visited -------- */
void resetVisited(int v) {
    int i;
    for (i = 0; i < v; i++)
        visited[i] = 0;
}

/* -------- Display graph -------- */
void display(Node *adj[], int v) {
    int i;
    Node *temp;

    printf("\nAdjacency List:\n");
    for (i = 0; i < v; i++) {
        printf("%d -> ", i);
        temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* -------- Main -------- */
int main() {
    Node *adj[MAX];
    int nv, ne, i, u, v, ch, start;

    printf("Enter number of vertices: ");
    scanf("%d", &nv);

    for (i = 0; i < nv; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &ne);

    for (i = 0; i < ne; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        insert_end(adj, u, v);
        insert_end(adj, v, u);   // Undirected graph
    }

    display(adj, nv);

    do {
        resetVisited(nv);

        printf("\n1. BFS");
        printf("\n2. BFT");
        printf("\n3. DFS");
        printf("\n4. DFT");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                printf("BFS: ");
                BFS(adj, start);
                break;

            case 2:
                printf("BFT: ");
                BFT(adj, nv);
                break;

            case 3:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                printf("DFS: ");
                DFS(adj, start);
                break;

            case 4:
                printf("DFT: ");
                DFT(adj, nv);
                break;

            case 0:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 0);

    return 0;
}





























