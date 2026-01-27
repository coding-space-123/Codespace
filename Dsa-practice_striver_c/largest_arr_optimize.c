//largest element by optimize way  TC=O(n)=  O(n)  SC=O(1)
#include<stdio.h>
#include<conio.h>
void main()
{
    int a[20];
    int i,temp,n,second_l,flag;
    printf("enter no. of terms =");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int largest=a[0];
    for(i=0;i<n;i++)
        if(largest < a[i])
        {
            // temp=a[i];
            // a[i]=largest;
            // largest=temp;
            largest=a[i];
        }
    second_l=-1;  
    printf("largest element is %d\n",largest);
return ;
}