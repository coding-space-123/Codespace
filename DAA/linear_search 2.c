#include<stdio.h>
int linear_search(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i; // Return the index if found
        }
    }    return 0; // Return -1 if not found
}

int main()
{
    int arr[10] ;
    int n ;
    int target;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int result = linear_search(arr, n, target);
    if(result != 0) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}