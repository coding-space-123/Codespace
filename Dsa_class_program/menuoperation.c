#include<stdio.h>
#include<stdlib.h>
#define size 10
void insert_last(int a[size], int *n ,int b);
void insert(int a[size], int *n ,int p, int b);
void delete_last(int a[size], int *n );
void delete_pos(int a[size], int *n ,int p);
int main()
{
	int a[size],i,p,b,*n,ch;
	do 
	{
	
		printf("enter no . of elements=");
		scanf("%d",&n);
		printf("enter elements=\t");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("elements before insertion :\n");
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
		printf("enter element to be insert=");
		scanf("%d",&b);
		printf("enter position =");
		scanf("%d",&p);
		switch(ch)
		{
			case 1: insert_last(a,&n,b);
					printf("update size =%d\n",*n);
					printf("elements after insertion :\n");
	  				for(i=0;i<n;i++)
					{
						printf("%d\n",a[i]);
					}
					break;
			case 2: insert(a,*n,p,b);
					printf("elements after insertion :\n");
	  				for(i=0;i<n;i++)
					{
						printf("%d\n",a[i]);
					}
					break;
			case 3: delete_last(a,&n);		
					printf("elements after deletion :\n");
	  				for(i=0;i<n;i++)
					{
						printf("%d\n",a[i]);
					}
					break;
			case 4: delete_pos(a,&n,p);	
					printf("elements after deletion :\n");
	  				for(i=0;i<n;i++)
					{
						printf("%d\n",a[i]);
					}
					break;
			case 5: exit(0);
		
			default: printf("invalid choose operation\n");			
		}
	}while(1);
return 0;	
}

void insert_last(int a[size],int *n,int b)
{
	if(*n==size)
	{
		printf("not performed insertion operation\n");
		return ;
	}
	a[*n]=v;
	(*n)++;
}

void insert_last(int a[size],int *n,int p,int b)
{
	if(p>=size ||n==size)
	{
		printf("invalid position\n");
		return ;
	}
}


