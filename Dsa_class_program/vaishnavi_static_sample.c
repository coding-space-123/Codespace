#include<stdio.h>
#include<conio.h>
int y=20;
void f()
{
	static int a=10;
	int z=5;
	z++;
	a++;
	y++;
	printf("a=%d\n",a);
	printf("z=%d\n",z);
//	printf("a=%d",x);
	printf("y=%d\n\n\n",y);
}
int main()
{
	int x=10;
	printf("y in main=%d\n",y);
	f();
	y++;
	f();
	y++;
	f();
	printf("y in main after call three times function f=%d\n",y);
}

