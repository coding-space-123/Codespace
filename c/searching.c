#include<stdio.h>
#include<stdlib.h>
int main()
{
    void linear(int a[30],int n,int s);
    void binary(int a[30],int n,int s);
    int a[30],n,s,i,ch;
    do{
        printf("***MENU SEARCHING***\n1.Linear search(data may be sorted or unsorted)\n 2.Binary search(if data is sorted)\n 3.exit \n");
        printf("\nenter no. of elements=");
        scanf("%d",&n);
        printf("enter elements of array=");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("enter element to be searched=");
        scanf("%d",&s);
        printf("enter your choice of searching=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: linear(a,n,s);
                    break;
            
            case 2: binary(a,n,s);
                    break;

            case 3: exit(0);
            default: printf("invalid choice\n");
        }
    } while(1);
return 0;
}

void linear(int a[30],int n,int s)
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            flag=1;
            printf("element is found at index %d\n",i);
            break;
        }
    }
    if(flag==0)
        printf("element not found\n");
}


void binary(int a[30],int n,int s)
{
    int l=0,u,mid,flag=0;
    u=n-1;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(a[mid]==s)
        {
            flag=1;
            break;
        }
        else if(a[mid]<s)
        {
            l=mid+1;
        }
        else
        {
            u=mid-1;
        }
    }
    if(flag==0)
        printf("element not found\n");
    else
    	printf("element found at index %d\n",mid);
   
    
}
