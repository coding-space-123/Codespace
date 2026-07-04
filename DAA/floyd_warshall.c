#include<stdio.h>

void floyd(int d[20][20],int l[20][20],int n)
{
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j]=l[i][j];
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
}
int main()
{















    int d[20][20],l[20][20],n,i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter distance matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&d[i][j]);
        }
    floyd(d,l,n);
    printf("Distance matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }
}