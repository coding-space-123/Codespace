//o/1 knap sack problem using backtracking
#include <stdio.h>

int n, m;
int w[20], p[20];
int x[20], y[20];
int fp = 0, fw = 0;

/* Bound Function */
float Bound(int cp, int cw, int k)
{
    int i, c;
    float b;

    b = cp;
    c = cw;

    for(i = k + 1; i <= n; i++)
    {
        if(c + w[i] <= m)
        {
            c = c + w[i];
            b = b + p[i];
        }
        else {
            return b + (m-c) * p[i] / w[i];
        }
    }

    return b;
}

/* Backtracking Knapsack */
void BKnapsack(int k, int cp, int cw)
{
    int j;

    /* Generate left child */
    if(cw + w[k] <= m)
    {
        y[k] = 1;

        if(k < n)
            BKnapsack(k + 1, cp + p[k], cw + w[k]);

        if((cp + p[k] > fp) && (k == n))
        {
            fp = cp + p[k];
            fw = cw + w[k];

            for(j = 1; j <= k; j++)
                x[j] = y[j];
        }
    }

    /* Generate right child */
    if(Bound(cp, cw, k) >= fp)
    {
        y[k] = 0;

        if(k < n)
            BKnapsack(k + 1, cp, cw);

        if((cp > fp) && (k == n))
        {
            fp = cp;
            fw = cw;

            for(j = 1; j <= k; j++)
                x[j] = y[j];
        }
    }
}

int main()
{
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    BKnapsack(1, 0, 0);

    printf("\nMaximum Profit = %d\n", fp);
    printf("Items selected:\n");

    for(i = 1; i <= n; i++)
        printf("%d ", x[i]);

    return 0;
}
/*
Enter number of items: 5
Enter knapsack capacity: 12
Enter weights:
4 6 3 4 2
Enter profits:
10 15 6 8 4

Maximum Profit = 29
Items selected:
1 1 0 0 1
*/