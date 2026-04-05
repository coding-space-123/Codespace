#include <stdio.h>
#define size 10

int t[size][3],p[size],c[size];
void unions(int i, int j);
int find(int a);
void min_heap(int arr[size], int n);
void heapify(int arr[size], int n, int i);
int delete(int arr[size], int *n);
int kruskal(int cost[size][size], int n, int *e);

int main(void)
{
    int i,j,n,e,v1,v2,v,ct,cost[size][size];
    printf("enetr number of vertices: ");
    scanf("%d",&n);
    printf("enetr number of edges: ");
    scanf("%d",&e);
    printf("enter edge and cost: ");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cost[i][j] = 999;
        }
    }
    for(i=1;i<=e;i++)
    {
        printf("enter vertices: ");
        scanf("%d%d",&v1,&v2);
        printf("enter cost: ");
        scanf("%d",&ct);
        c[i]=ct;
        cost[v1][v2] = ct;
        cost[v2][v1] = ct;
    }
    printf("\ncost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf(" %d ",cost[i][j]);
        }
        printf("\n");
    }
    int mincost = kruskal(cost,n,&e);
    printf("\n min cost: %d\n",mincost);
}

void heapify(int arr[size], int n, int i)
{
    int l,r,min,temp;
    min = i;
    l = 2*i;
    r = 2*i + 1;
    if(l<=n && arr[l] < arr[min])
    {
        min = l;
    }
    if(r<=n && arr[r] < arr[min])
    {
        min = r;
    }
    if(min != i)
    {
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        heapify(arr,n,min);
    }
}

void min_heap(int arr[size], int n)
{
    for(int i=(n/2);i>=1;i--)
        heapify(arr,n,i);
}

int delete(int arr[size], int *n)
{
    if(*n==0)
    {
        printf("heap is empty!\n");
        return 0;
    }
    int x = arr[1];
    arr[1] = arr[*n];
    (*n)--;
    heapify(arr,*n,1);
    return x;
}

void unions(int i, int j)
{
    p[i] = j;
}

int find(int a)
{
    int j = a;
    while(p[j]>0)
        j=p[j];
    return j;
}
int kruskal(int cost[size][size], int n, int *e)
{
    int i,j,k,mincost = 0,x,u,v;
    min_heap(c,*e);
    i = 0;
    for(i=1;i<=n;i++)
        p[i] = -1;
    while((i<n-1) && *e!=0)
    {
        x = delete(c,e);
        for(k=1;k<=n;k++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[k][j]==x)
                {
                    u = k;
                    v = j;
                }
            }
        }
        j = find(u);
        i = find(v);
        if(j!=i)
        {
            i++;
            t[i][1] = u;
            t[i][2] = v;
            mincost += cost[u][v];
            unions(u,v);
        }
    }
    if(i<n-1)
        printf("\nmo mst!");
    return mincost;
}