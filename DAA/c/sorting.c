#include<stdio.h>
#include<stdlib.h>
int main()
{
    void selection(int a[30],int n);
    void bubble(int a[30],int n);
    void insertion(int a[30],int n);
    
    int a[30],n,s,i,ch;
    do{
        printf("***MENU Sorting***\n1.selection sort\n 2.bubble sort\n 3.insertion sort\n 4.exit \n");
        printf("\nenter no. of elements=");
        scanf("%d",&n);
        printf("enter elements of array=");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        printf("enter your choice of searching=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: selection(a,n);
            		printf("after sorting array=\t");
        			for(i=0;i<n;i++)
        			{
        			    printf("%d\n",a[i]);
        			}
                    break;
            
            case 2: bubble(a,n);
            		printf("after sorting array=\t");
        			for(i=0;i<n;i++)
        			{
        			    printf("%d\n",a[i]);
        			}
                    break;
			case 3: insertion(a,n);
					printf("after sorting array=\t");
        			for(i=0;i<n;i++)
        			{
        			    printf("%d\n",a[i]);
        			}
					break;
            case 4: exit(0);
            default: printf("invalid choice\n");
        }
    } while(1);
return 0;
}

void selection(int a[30],int n)
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


void bubble(int a[30],int n)
{
	int i,j,temp,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
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

void insertion(int a[30],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0  &&  temp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}