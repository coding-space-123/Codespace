#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct Queue
{
	int f,r;
	int a[size];
	
}queue;

void enque(queue*,int );
int deque(queue*);
void display(queue*);
int isempty(queue* );
int isfull(queue* );



int main()
{
	int v,p,ch,t;
	queue q;
	q.f=q.r=-1;
	printf("\n***MENU OF QUEUE OPERATION***\n");
	printf("1.push operation \n 2. pop operation \n 3. display\n4.exit\n");
	
	do
	{
		printf("\nenter your choice of operation :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter value to be push in linear queue:");
					scanf("%d",&v);
					enque(&q,v);
					display(&q);
//					printf("\ntop value is %d and top element is %d\n",top,stack[top]);
					break;
			case 2: p=deque(&q);
					printf("\ndeque value is%d\n",p);
					
					break;
			case 3:	display(&q);
					break;		
			case 4: exit(0);
						
			default: printf("invalid choice\n");			
		}		
	}while(1);
return 0;
}

void enque(queue *q ,int v)
{
	if(isfull(q))
	{
		printf("queue is full\n");
		return ;
	}
	if(q->f==-1)
		q->f=0;
	q->a[++(q->r)]=v;
	return;
}


int deque(queue *q)
{
	int p;
	if(isempty(q))
	{
		printf("stack is underflow i.e no element in queue\n");
		return ;
	}
	p= q->a[(q->f)];
	if(q->f==q->r)
		q->f=q->r=-1;
	else 
		(q->f)++;
	return p;
}



void display (queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("queue  is empty i.e under flow\n");
		return ;
	}
	printf("element in queue is\n");
	for(i=q->f;i<=q->r;i++)
		printf("%d\n",q->a[i]);
}

int isempty(queue *q)
{
	if(q->f==-1)
	{
		return 1;
	}
	else 
		return 0;	
	
}

int isfull(queue *q)
{
	if(q->r==size-1)
		return 1;
	else 
		return 0;
		
}
