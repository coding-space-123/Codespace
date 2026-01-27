// two pointer approach 
//TC=O(j)+O(n-j)=O(n)     ......SC=O(1) -in place

#include<stdio.h>
void moves_zero(int a[],int n)
{
    int j=-1,i;
    for(i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            j=i;
            break;
        }
    
    }

    for(i=j+1;i<n;i++)
    {
        if(a[i] != 0)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j++;
        }
    }
}



int main() {
    int a[] = {1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(a)/sizeof(a[0]);

    moves_zero(a, n);

    // Print result
    printf("Array after moving zeros:\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}


// Dry Run Example

// Array: [1, 0, 2, 3, 2, 0, 0, 4, 5, 1]

// First zero → j=1.

// Now scan from i=2 onward:

// i=2 → a[2]=2 (non-zero) → swap with a[1].
// Array → [1, 2, 0, 3, 2, 0, 0, 4, 5, 1], j=2.

// i=3 → a[3]=3 → swap with a[2].
// Array → [1, 2, 3, 0, 2, 0, 0, 4, 5, 1], j=3.

// i=4 → a[4]=2 → swap with a[3].
// Array → [1, 2, 3, 2, 0, 0, 0, 4, 5, 1], j=4.

// i=7 → a[7]=4 → swap with a[4].
// Array → [1, 2, 3, 2, 4, 0, 0, 0, 5, 1], j=5.

// i=8 → a[8]=5 → swap with a[5].
// Array → [1, 2, 3, 2, 4, 5, 0, 0, 0, 1], j=6.

// i=9 → a[9]=1 → swap with a[6].
// Array → [1, 2, 3, 2, 4, 5, 1, 0, 0, 0], j=7.

