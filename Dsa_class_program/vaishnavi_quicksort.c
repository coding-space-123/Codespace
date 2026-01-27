#include <stdio.h>
#include <stdlib.h>
#define size 50  

int partition(int a[size], int l, int u) 
{
    int p = a[l];
    int i = l + 1, j = u, temp;

    while (i <= j) 
	{
        while (i <= u && a[i] <= p)
            i++;
        while (a[j] > p)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    if (l != j) {
        temp = a[l];
        a[l] = a[j];
        a[j] = temp;
    }
    return j;  
}

void quicksort(int a[size], int l, int u) 
{
    int p;
    if (l < u) 
	{
        p = partition(a, l, u);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, u);
    }
}

int main() 
{
    int a[size], n, i;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d\n ", a[i]);

    return 0;
}

