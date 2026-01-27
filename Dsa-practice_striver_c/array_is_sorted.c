#include <stdio.h>

int main()
{
    int a1[20], a2[20];
    int n1, n2, i, sorted;

    // First array
    printf("Enter number of elements in 1st array: ");
    scanf("%d", &n1);
    printf("Enter elements of 1st array: ");
    for (i = 0; i < n1; i++)
        scanf("%d", &a1[i]);

    sorted = 1;
    for (i = 0; i < n1 - 1; i++)
        if (a1[i] > a1[i + 1])
            sorted = 0;
    if (sorted)
        printf("First array is sorted in ascending order.\n");
    else
        printf("First array is NOT sorted in ascending order.\n");

    // Second array
    printf("Enter number of elements in 2nd array: ");
    scanf("%d", &n2);
    printf("Enter elements of 2nd array: ");
    for (i = 0; i < n2; i++)
        scanf("%d", &a2[i]);

    sorted = 1;
    for (i = 0; i < n2-1 ; i++)
        if (a2[i] > a2[i + 1])
            sorted = 0;
    if (sorted)
        printf("Second array is sorted in ascending order.\n");
    else
        printf("Second array is NOT sorted in ascending order.\n");

    return 0;
}
