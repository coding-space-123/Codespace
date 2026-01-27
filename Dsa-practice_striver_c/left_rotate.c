//left rotate on array by one place
//  brute force approach ... TC=O(n)  SC=O(1)
#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5};
    int n= sizeof (a)/ sizeof(a[0]);
    int temp=a[0];
    for(int i=1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    a[n-1]=temp;
    printf("left rotate:\t");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}