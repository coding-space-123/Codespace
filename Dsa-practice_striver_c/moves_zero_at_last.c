#include <stdio.h>
//brute force approach 
// SC=O(j).....TC=O(n)+O(j)+O(n-j)=O(2n)
void moves_zero(int a[], int n) {
    int temp[20];  // assume array size <= 20
    int j = 0;

    // Step 1: store all non-zero elements in temp
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp[j] = a[i];
            j++;
        }
    }

    // Step 2: fill original array with non-zeros first
    for (int i = 0; i < j; i++) {
        a[i] = temp[i];
    }

    // Step 3: put remaining places as 0
    for (int i = j; i < n; i++) {
        a[i] = 0;
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
