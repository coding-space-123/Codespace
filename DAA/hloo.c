#include<stdio.h>
int m, g[20][20], x[20];
void nextvalue(int k)
{
    int j;
    do{
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k]==0)
        {
            return ;
        }
        for(j=1;j<=k-1;j++)
        {
            if(g[k][j]==1 && x[k]==x[j])
            {
                break;
            }
        }
        if(j==k)
        {
            return ;
        }
    }while(1);
}
void mcoloring(int k, int n)
{
    int j;
    do{
        nextvalue(k);
        if(x[k]==0)
        {
            return ;
        }
        if(k==n)
        {
            for(int i=1;i<=n;i++)
            {
                printf("%d ",x[i]);
            }
            printf("\n");
            return ;
        }
        mcoloring(k+1,n);
    }while(1);
}

int main()
{
    int n;
    printf("enter no . of vertex of graph: ");
    scanf("%d",&n);
    printf("enetr no. of color:");
    scanf("%d",&m);
    printf("enter adjacency matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    printf("matrix is:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("possible colorings are:\n");
    mcoloring(1,n);
    return 0;
}














