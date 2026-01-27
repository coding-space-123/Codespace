#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct double_stack
{
	int top1,top2;
	int a[size];
}stack;


int peek(stack s,int id);
int isempty(stack s ,int id);
int isfull(stack s ,int id );
void push(stack *s , int id , int v);
int pop(stack *s , int id);
void display(stack s ,int id);

int main()
{
	stack s;
	s.top1=-1;
	s.top2=size;
	int v,ch,id;
	printf("\n****MENU*****\n");
	printf("\n1.Push\n2.Pop\n3.peek\n4.Display elements\n5.Exit\n");
	do
	{
		
		printf("enter your stack id:");
		scanf("%d",&id);
		if(id==1 || id==2)
		{
			printf("enter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: printf("enter value to be pushed:");
						scanf("%d",&v);
						push(&s,id,v);
						break;
				case 2: v=pop(&s,id);
						if(v != -999)
						printf("popped value of stack %d :%d\n",id,v);
						break;
				case 3:	v=peek(s,id);
						printf("peek value of stack %d:%d\n",id,v);
						break;
				case 4: display(s,id);
						break;
				case 5: exit(0);
				default: printf("invalid choice\n");				
			}
	
		}
		else
		printf("invalid stack\n");
	}while(1);

}


int isempty(stack s ,int id)
{
	if(id==1 && s.top1==-1)
	{
		printf("stack %d is empty",id);
		return 1;
	}
		
	else if(id==2 && s.top2==size)
	{
		printf("stack %d is empty\n",id);
		return 1;
	}
	else
		return 0;
		
}
int isfull(stack s , int id )
{
	if(s.top1==s.top2-1)
	{
		printf("stack %d is full\n",id);
		return 1;
	}
	else
		return 0;
}

void push(stack *s , int id , int v)
{
	if(id==1)
	{
		if(isfull(*s ,id))
			return;
		s->a[++(s->top1)]=v;
	}
	else if(id==2)
	{
		if(isfull(*s ,id))
			return;
		s->a[--(s->top2)]=v;
	}
	else
		return;
}

int pop(stack *s , int id)
{
	if(id==1)
	{
		if(isempty(*s,id))
			return -999;
		return s->a[(s->top1)--];
	}
	else if(id==2)
	{
		if(isempty(*s,id))
			return -999;
		return s->a[(s->top2)++];
	}
	else
		return 0;
}

void display(stack s , int id)
{
	int i;
	if(id==1)
	{
		if(isempty(s,id))
			return;
		for(i=s.top1;i>=0;i--)
			printf("%d\n",s.a[i]);			
	}
	else if(id==2)
	{
		if(isempty(s,id))
			return;
		for(i=s.top2;i<size;i++)
			printf("%d\n",s.a[i]);			
	}
}

int peek(stack s,int id)
{
	if(id==1)
	{
		if(isempty(s,id))
			return ;
		return s.a[s.top1];
	}
	else if(id==2)
	{
		if(isempty(s,id))
			return 1;
		return s.a[s.top2];
	}
	else
		return 0;
	
}
