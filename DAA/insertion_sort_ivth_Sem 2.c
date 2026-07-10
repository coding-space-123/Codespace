#include<stdio.h>

void insertion_sort(int arr[], int n) 
{ 
    int i, item, j; 
    printf("%d \n",arr[0]);
    for (i = 1; i < n; i++) { 
        item = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > item) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = item; 
        for(int k=0; k <= i ; k++)
            printf("%d ",arr[k]);
        printf("\n");
    } 
}











int main() 
{
    int arr[10] ;
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array before sorting: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nSorting process:\n");
    insertion_sort(arr, n);
    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
