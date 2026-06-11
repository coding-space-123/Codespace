#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/* -------- Global Variables -------- */
int front = -1, rear = -1;
int visited[MAX];
int q[MAX];

/* -------- Function Prototypes -------- */
void insertQ(int x);
int deleteQ();
int emptyq();
void bfs(int g[20][20], int nv, int v);
void bft(int g[20][20], int nv);
void displaygraph(int g[20][20], int nv);

/* -------- Main -------- */

int main()
{
    int g[20][20], nv, ne;
    int i, j, v1, v2, v, ch;

    printf("Enter number of vertices for edges: ");
    scanf("%d", &nv);

    for (i = 1; i <= nv; i++)
        for (j = 1; j <= nv; j++)
            g[i][j] = 0;

    printf("Enter number of edges in graph: ");
    scanf("%d", &ne);

    for (i = 1; i <= ne; i++)
    {
        printf("Enter edge e%d between the vertices: ", i);
        scanf("%d%d", &v1, &v2);
        g[v1][v2] = 1;
        g[v2][v1] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    displaygraph(g, nv);
    printf("\n\n----- MENU -----");
    printf("\n1. Breadth First Search (BFS)");
    printf("\n2. Breadth First Traversal (BFT)");
    printf("\n3. Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        for (i = 1; i <= nv; i++)
            visited[i] = 0;
        switch (ch)
        {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &v);
                printf("BFS Traversal: ");
                bfs(g, nv, v);
                break;

            case 2:
                printf("BFT Traversal: ");
                bft(g, nv);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice");
        }
    } while (1);

    return 0;
}

/* -------- Queue Functions -------- */

void insertQ(int x)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    q[++rear] = x;
}
int deleteQ()
{
    return q[front++];
}
int emptyq()
{
    return (front > rear || front == -1);
}
/* -------- BFS -------- */

















void bfs(int g[20][20], int nv, int v)
{
    int w;
    insertQ(v);
    visited[v] = 1;
    printf("%d ", v);
    while (!emptyq())
    {
        v = deleteQ();

        for (w = 1; w <= nv; w++){
            if (g[v][w] == 1 && visited[w] == 0){
                insertQ(w);
                visited[w] = 1;
                printf("%d ", w);
            }
        }
    }
}
/* -------- BFT -------- */


































void bft(int g[20][20], int nv)
{
    int i;
    for (i = 1; i <= nv; i++)
    {
        if (visited[i] == 0)
            bfs(g, nv, i);
    }
}

/* -------- Display Graph -------- */

void displaygraph(int g[20][20], int nv)
{
    int i, j;

    for (i = 1; i <= nv; i++)
    {
        for (j = 1; j <= nv; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}
