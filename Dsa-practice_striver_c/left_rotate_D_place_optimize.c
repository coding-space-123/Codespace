//Time: O(n) (each element swapped a constant number of times)

//Space: O(1) (in-place, no extra array needed)

#include <stdio.h>

// function to reverse a portion of the array
void reverse(int a[], int start, int end) 
{
    while (start < end) 
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    int a[] = {1,2,3,4,5,6,7};
    int d = 3, n = sizeof(a)/sizeof(a[0]);

    d = d % n; // handle case when d > n

    // Step 1: reverse first d elements
    reverse(a, 0, d-1);  //3,2,1,4,5,6,7

    // Step 2: reverse remaining n-d elements
    reverse(a, d, n-1);  //3,2,1,7,6,5,4

    // Step 3: reverse whole array
    reverse(a, 0, n-1);  //4,5,6,7,3,2,1

    // Print result
    printf("Left rotate by %d:\t", d);
    for (int i=0; i<n; i++)
        printf("%d\t", a[i]);

    return 0;
}
