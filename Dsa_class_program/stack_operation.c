#include<stdio.h>
#include<stdlib.h>
#define size 5
void push(int stack[size],int *top,int v);
int pop(int a[size],int *top); 
int peek(int a[size],int *top);
void display(int a[size],int *top); 
void isempty(int stack[size],int top);
void isfull(int stack[size],int top);
int main()
{
	int stack[size],top=-1, n, i, ch,p,v,t;
	printf("\n***MENU OF STACK OPERATION***\n");
	printf("1.push operation \n 2. pop operation \n 3. peek operation \n 4.display\n5.isempty\n 6.isfull\n 7.exit\n");
	
	do
	{
		printf("\nenter your choice of operation :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter value to be push:");
					scanf("%d",&v);
					push(stack,&top,v);
					display(stack,&top);
//					printf("\ntop value is %d and top element is %d\n",top,stack[top]);
					break;
			case 2: p=pop(stack,&top);
					printf("\npopped value is%d\n",p);
					display(stack,&top);
					break;
			case 3: t=peek(stack,&top);
					printf("\n peek value is %d\n",t);
					display(stack,&top);
					break;
			case 4:	display(stack,&top);
					break;
			case 5: isempty(stack,top);
					break;
			case 6: isfull(stack,top);	
					break;		
			case 7: exit(0);
						
			default: printf("invalid choice\n");			
		}		
	}while(1);
return 0;
}

void push(int stack[size],int *top ,int v)
{
	if(*top==size-1)
	{
		printf("stack is overflow\n");
		return ;
	}
	stack[++(*top)]=v;
	return;
}

int pop(int stack[size],int *top)
{
	int v;
	if(*top==-1)
	{
		printf("stack is underflow\n");
		return;
	}
	v=stack[(*top)--];
	return v;
}

int peek(int stack[size], int *top)
{
	int t;
	if(*top==-1)
	{
		printf("stack is empty\n");
		return ;
	}
	t=stack[*top];
	return t;
}

void display (int stack[size], int *top)
{
	int i;
	if(*top==-1)
	{
		printf("stack is empty i.e under flow\n");
		return;
	}
	printf("element in stack is\n");
	for(i=*top;i>-1;i--)
		printf("%d\n",stack[i]);
}

void isempty(int stack[size], int top)
{
	if(top<size-1)
		printf("stack is empty\n");
	else 
		printf("stack is not empty\n");	
	
}

void isfull(int stack[size], int top)
{
	if(top==size-1)
		printf("stack is full\n");
	else 
		printf("stack is not full\n");
		
}
