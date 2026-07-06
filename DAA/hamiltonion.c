#include<stdio.h>

int g[20][20];   
int x[20];       
int n;

void nextvalue(int k)
{
    int i;
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if(x[k] == 0)
            return;
        if(g[x[k-1]][x[k]] != 0)  
        {
            for(i = 1; i < k; i++)
            {
                if(x[i] == x[k])  
                    break;
            }
            if(i == k){
                if(k < n || (k == n && g[x[n]][x[1]] != 0))
                    return;
            }
        }
    } while(1);
}
void hamiltonian(int k)
{
    int i;
    do
    {
        nextvalue(k);
        if(x[k] == 0)
            return;
        if(k == n)
        {
            for(i = 1; i <= n; i++)
                printf("%d ", x[i]);

            printf("%d", x[1]);   
            printf("\n");
        }
        else
        {
            hamiltonian(k + 1);
        }

    } while(1);
}

int main()
{
    int i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)





























            scanf("%d",&g[i][j]);
    x[1] = 1;   
    printf("All possible Solutions:\n");
    hamiltonian(2);  
    return 0;
}