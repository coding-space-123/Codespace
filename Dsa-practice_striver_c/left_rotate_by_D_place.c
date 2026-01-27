//left rotate element by d places 
//TC=O(d)+O(n-d)+O(n+d)=O(n+d) ...... SC=O(d) 

#include <stdio.h>

int main() 
{
    int a[] = {1,2,3,4,5,6,7};
    int d = 3, n = sizeof(a) / sizeof(a[0]);

    // Step 1: Save first d elements
    int temp[d];
    for(int i=0; i<d; i++) 
    {
        temp[i] = a[i];
    }

    // Step 2: Shift remaining elements left
    for(int i=d; i<n; i++) 
    {
        a[i-d] = a[i];
    }

    // Step 3: Copy saved elements to end
    int j = 0;
    for(int i=n-d; i<n; i++) {
        a[i] = temp[j];
        j++;
    }

    // Print result
    printf("Left rotate:\t");
    for(int i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}
