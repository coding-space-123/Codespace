#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct Stack
{
	int top;
	int a[size];
	



}stack;
void push(stack *,int );
int pop(stack*);
int peek(stack);
void display(stack);
int isempty(stack);
int isfull(stack);



int main()
{
	int v,p,ch,t;
	stack s;
	s.top=-1;
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
					push(&s,v);
					display(s);
//					printf("\ntop value is %d and top element is %d\n",top,stack[top]);
					break;
			case 2: p=pop(&s);
					printf("\npopped value is%d\n",p);
					display(s);
					break;
			case 3: t=peek(s);
					printf("\n peek value is %d\n",t);
					break;
			case 4:	display(s);
					break;
			case 5: if(isempty(s))
						printf("stack is empty \n");
					else
						printf("stack is full\n");
					break;
			case 6: if(isfull(s))
						printf("stack is full\n");	
					else
						printf("stack is empty \n");
					break;		
			case 7: exit(0);
						
			default: printf("invalid choice\n");			
		}		
	}while(1);
return 0;
}

void push(stack *s ,int v)
{
	if(s->top==size-1)
	{
		printf("stack is overflow\n");
		return ;
	}
	s->a[++(s->top)]=v;
	return;
}


int pop(stack *s)
{
	int p;
	if(s->top==-1)
	{
		printf("stack is underflow i.e no element in stack\n");
		return ;
	}
	p=s->a[(s->top)--];
	return p;
}


int peek(stack s)
{
	int t;
	if(s.top==-1)
	{
		printf("stack is empty\n");
		return ;
	}
	t=s.a[s.top];
	return t;
}

void display (stack s)
{
	int i;
	if(s.top==-1)
	{
		printf("stack is empty i.e under flow\n");
		return;
	}
	printf("element in stack is\n");
	for(i=s.top;i>-1;i--)
		printf("%d\n",s.a[i]);
}

int isempty(stack s)
{
	if(s.top==-1)
	{
		printf("%d\n",s.top);
		return 1;
	}
	else 
		return 0;	
	
}

int isfull(stack s)
{
	if(s.top==size-1)
		return 1;
	else 
		return 0;		
}



























