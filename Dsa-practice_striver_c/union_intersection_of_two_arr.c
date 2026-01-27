#include<stdio.h>
void union_intersection(int A[], int n1, int B[], int n2) {
    int i = 0, j = 0;

    printf("Union: ");
    while (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        } 
        else if (B[j] < A[i]) {
            printf("%d ", B[j]);
            j++;
        } 
        else {  // A[i] == B[j]
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements
    while (i < n1) {
        printf("%d ", A[i]);
        i++;
    }
    while (j < n2) {
        printf("%d ", B[j]);
        j++;
    }

    printf("\nIntersection: ");
    i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (A[i] < B[j]) {
            i++;
        } 
        else if (B[j] < A[i]) {
            j++;
        } 
        else {
            printf("%d ", A[i]);
            i++;
            j++;
        }
    }
    printf("\n");
}

int main() {
    int A[] = {1, 2, 4, 5, 6};
    int B[] = {2, 3, 5, 7};
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);

    union_intersection(A, n1, B, n2);

    return 0;
}
