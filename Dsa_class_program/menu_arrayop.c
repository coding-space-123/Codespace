#include<stdio.h>
#include<stdlib.h>
#define size 5
void insert_last(int a[size],int *n,int v);
void insert_pos(int a[size],int *n,int p,int v); 
void delete_last(int a[size],int *n);
void delete_pos(int a[size],int *n,int p); 
int main()
{
	int a[size], n, i, ch,p,v;
	printf("\n***MENU OF ARRAY OPERATION***\n");
	printf("1.insert at last \n 2. insert at given position \n 3. delete at last \n 4.delete at given position\n");
		
	printf("\nenter no. of element=");
	scanf("%d",&n);
	printf("enter elements of array:\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("elements before applied array operation are \n");
		for(i=0;i<n;i++)
			printf("%d",a[i]);
	do
	{
		printf("\nenter your choice of operation :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter value to be insert at last position:");
					scanf("%d",&v);
					insert_last(a,&n,v);
					printf("elements after applied array operation are \n");
					for(i=0;i<n;i++)
						printf("%d\n",a[i]);
					printf("\nnow no of terms in array is%d\n",n);
					break;
			case 2: printf("\nenter position where value to be insert:");
					scanf("%d",&p);
					printf("enter value to be insert at given position:");
					scanf("%d",&v);
					insert_pos(a,&n,p,v);
					printf("elements after applied array operation are \n");
					for(i=0;i<n;i++)
						printf("%d\n",a[i]);
					printf("\nnow no of terms in array is%d\n",n);
					break;
			case 3: delete_last(a,&n);
					printf("elements after applied array operation are \n");
					for(i=0;i<n;i++)
						printf("%d\n",a[i]);
					printf("\nnow no of terms in array is%d\n",n);
					break;
			case 4: printf("\nenter position where value to be deleted:");
					scanf("%d",&p);
					delete_pos(a,&n,p);
					printf("elements after applied array operation are \n");
					for(i=0;i<n;i++)
						printf("%d\n",a[i]);
					printf("\nnow no of terms in array is%d\n",n);
					break;
			case 5: exit(0);
						
			default: printf("invalid choice\n");			
		}		
	}while(1);
return 0;
}

void insert_last(int a[size], int *n , int v)
{
	if(*n==size)
	{
		printf("array is full\n");
		return ;
	}	
	a[*n]=v;
	(*n)++;
	
}

void insert_pos(int a[size],int *n,int v,int p)
{
	int i;
	if(p>=size || *n==size)
	{
		printf("array is full or may be enter invalid position\n ");
		
	}
		for(i=*n;i>=p-1;i--)
			a[i+1]=a[i];
		a[p-1]=v;
		(*n)++;
		return ;
	
	
}

	
void delete_last(int a[size], int *n )
{
	if(*n==0)
	{
		printf("array is empty\n");
		return ;
	}	
	
	--(*n);
	
}

void delete_pos(int a[size],int *n,int p)
{
	int i;
	if(p>=size || *n==0)
	{
		printf("array is empty or may be enter invalid position\n ");
		return;
		
	}
		for(i=p;i<=*n;i++)
			a[i-1]=a[i];
		--(*n);
	
}	
	
	

