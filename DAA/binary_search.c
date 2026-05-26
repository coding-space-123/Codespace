#include<stdio.h>
int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int j=0;
    while(low <= high && j==0) {
        int mid = (low + high) / 2;
        if(arr[mid] == target) {
            j = mid; 
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return j; 
}
int main()
{
    int arr[10] ;
    int n ;
    int target;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int result = binary_search(arr, n, target);
    if(result != 0) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}














































































