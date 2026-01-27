#include<stdio.h>
int main(){
    void selectionsort(int a[30],int n);
    int i,a[30],n=5;
    printf("enter array elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    printf("sorted array elements=");
    for(i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
return 0;
}

void selectionsort(int a[30],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}