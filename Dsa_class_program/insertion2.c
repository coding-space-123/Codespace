#include<stdio.h>
#define size 20
int insertion(int a[20], int n, int p ,int b);
int main()
{
	int a[size],i,p,b,n,x;
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
	x=insertion(a,n,p,b);
	printf("elements after insertion :\n");
	printf("now size of array=%d\n",x);
	for(i=0;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}
return 0;	
}


int insertion (int a[size], int n, int p ,int b)
{
	int i;
	if(n < size)
	{
		for(i=n;i>=p-1;i--)
		{
		a[i+1]=a[i];	
		}
		a[p-1]=b;
		n++;
	}
	return n;
	
}
