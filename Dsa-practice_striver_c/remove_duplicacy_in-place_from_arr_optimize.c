// optimize approach ..TC=O(n) ....SC=O(1)
#include <stdio.h>

int main() 
{
    int arr[] = {1,1,2,2,3,3,3,4,4};
    int n = 9;
    int j = 0; 

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[j]) 
        {  
            j++;
            arr[j] = arr[i];  // place new unique element
        }
    }

    // now first (j+1) elements are unique
    for (int i = 0; i <= j; i++)
        printf("%d ", arr[i]);

    return 0;
}
