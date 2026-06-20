#include<stdio.h>
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}
int main() {
    int arr[10];
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
    selection_sort(arr, n);
    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}