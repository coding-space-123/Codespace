#include<stdio.h>
int x[20];
int g[20][20];
void nextvalue(int k, int n)
{
    int i;
    do{
        x[k] = (x[k] + 1) % (n + 1);
        if(x[k] == 0)
            return;
        for(i = 1; i <= k - 1; i++)
        {
            if(g[k][i] == 1 && x[i] == x[k])
                break;
        }
        if(i == k)
            return;
    }while(x[k] != 0);
}

void mcolouring(int k, int n)
{
    do{
        nextvalue(k, n);
        if(x[k] == 0)
            return;
        if(k == n)
        {
















            for(int i = 1; i <= n; i++)
                printf("%d ",x[i]);
            printf("\n");
        }
        else
            mcolouring(k + 1, n);
    }while(x[k] != 0);
}

int main()
{
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);
    printf("The adjacency matrix is:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
    printf("All possible Solutions: \n");
    mcolouring(1, n);
}