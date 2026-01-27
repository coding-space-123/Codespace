//remove duplicacy in-place from  sorted array 
//  brute force approach ... TC=O(n)  SC=O(n)
#include <stdio.h>

int main() 
{
    int arr[] = {1,1,2,2,2,3,3,3,4,4};
    int n = 10;
    int temp[10];
    int j = 0;

    // Collect only unique elements
    for (int i = 0; i < n-1; i++) 
    {
        if (arr[i] != arr[i+1]) 
        {
            temp[j] = arr[i];
            j++;
        }
    }
    // Last element is always unique in this logic
    temp[j++] = arr[n-1];

    // Copy back into original array
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    // Print
    for (int i = 0; i < j; i++)
        printf("%d ", arr[i]);

    return 0;
}
