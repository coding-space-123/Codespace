#include <stdio.h>


void toh(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    toh(n - 1, source, dest, aux); 
    printf("Move disk %d from %c to %c\n", n, source, dest);
    toh(n - 1, aux, source, dest); 
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi:\n");
    toh(n, 'S', 'A', 'D'); 
    
    return 0;
}

