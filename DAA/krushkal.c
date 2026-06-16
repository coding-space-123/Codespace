#include <stdio.h>
#define size 20 
int t[size][3], p[size], c[size];
void unions(int i, int j);
int find(int a);
void min_heap(int arr[size], int n);
void heapify(int arr[size], int n, int i);
int delete(int arr[size], int *n);
int kruskal(int cost[size][size], int n, int *e);






















int main(void)
{
    int i, j, n, e, v1, v2, ct, cost[size][size];
    printf("enter number of vertices: ");
    scanf("%d", &n);
    printf("enter number of edges: ");
    scanf("%d", &e);
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cost[i][j] = 999;
        }
    }
    for(i = 1; i <= e; i++) {
        printf("enter vertices and cost: ");
        scanf("%d%d%d", &v1, &v2, &ct);
        c[i] = ct;
        cost[v1][v2] = ct;
        cost[v2][v1] = ct;
    }

    int mincost = kruskal(cost, n, &e);
    printf("edges in the minimum spanning tree:\n");
    for(i = 1; i <= n - 1; i++) {
        printf("%d %d -> %d\n", t[i][1], t[i][2], c[i]);
    }
    printf("\nmin cost: %d\n", mincost);
    return 0;
}
void heapify(int arr[size], int n, int i)
{
    int l, r, min, temp;
    min = i;
    l = 2 * i;
    r = 2 * i + 1;
    if(l <= n && arr[l] < arr[min]) min = l;
    if(r <= n && arr[r] < arr[min]) min = r;
    if(min != i) {
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        heapify(arr, n, min);
    }
}

void min_heap(int arr[size], int n)
{
    for(int i = (n / 2); i >= 1; i--)
        heapify(arr, n, i);
}

int delete(int arr[size], int *n)
{
    if(*n == 0) return 0;
    int x = arr[1];
    arr[1] = arr[*n];
    (*n)--;
    heapify(arr, *n, 1);
    return x;
}

void unions(int i, int j)
{
    p[i] = j; 
}

int find(int a)
{
    while(p[a] > 0)
        a = p[a];
    return a;
}

int kruskal(int cost[size][size], int n, int *e)
{
    int i, j, k, mincost = 0, x, u, v, count = 0;
    min_heap(c, *e);
    
    for(i = 1; i <= n; i++) p[i] = 0; 

    while(count < n - 1 && *e != 0)
    {
        x = delete(c, e);
        int flag = 0;
        
        // Cost matrix mein vertices dhoondhna aur mark karna
        for(k = 1; k <= n && flag == 0; k++) {
            for(j = 1; j <= n; j++) {
                if(cost[k][j] == x) {
                    u = k; v = j;
                    cost[k][j] = cost[j][k] = 999; // Edge mark ki taaki repeat na ho
                    flag = 1;
                    break;
                }
            }
        }

        j = find(u);
        k = find(v);
        
        if(j != k)
        {
            count++;
            t[count][1] = u;
            t[count][2] = v;
            mincost += x;
            unions(j, k); // Roots ko connect kiya
        }
    }
    return mincost;
}
// 1 6 10 3 4 12 2 7 14 2 3 16 4 7 18 4 5 22 5 7 24 5 6 25 1 2 28 1 5 30 