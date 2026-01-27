#include<stdio.h>
int main()
{
    void bubblesort(int a[40],int n);
    int i,a[40],n;
    printf("enter no.of elements=");
    scanf("%d",&n);
    printf("enter element=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("sorted element=");
    for(i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
return 0;
}

void bubblesort(int a[40],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                flag=1;
            }
            if(flag==1)
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}