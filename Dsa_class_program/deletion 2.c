#include<stdio.h>
int main()
{
	int a[20],i,p,b,n;
	printf("enter no . of elements=");
	scanf("%d",&n);
	printf("enter elements=\t");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("elements before deletion :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("enter element to be deleted=");
	scanf("%d",&b);
//	printf("enter position =");
//	scanf("%d",&p);
//	if(p<=0 && p>n+1)
//	{
//		printf("deletion is not possible\n");
//	}
//	else
		for(i=p-1;i<n-1;i++)
		{
		a[i]=a[i+1];	
		}
	
	printf("elements after deletion :\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d\n",a[i]);
	}
return 0;	
}
