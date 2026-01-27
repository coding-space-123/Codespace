#include <stdio.h>

void bubble_sort(int arr[], int n);

int main() {
    int arr[10];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nArray before sorting: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nSorting steps:\n");
    bubble_sort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;   

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }

        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

        if (flag == 0)
            break;
    
}
