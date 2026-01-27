#include<stdio.h>
#include<stdlib.h>
#define size 5

typedef struct Queue
{
	int f,r;
	int a[size];
	
}queue;

void cenque(queue*,int );
int cdeque(queue*);
void cdisplay(queue*);
int cisempty(queue* );
int cisfull(queue* );



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
					cenque(&q,v);
					cdisplay(&q);
//					printf("\ntop value is %d and top element is %d\n",top,stack[top]);
					break;
			case 2: p=cdeque(&q);
					printf("\ndeque value is%d\n",p);
					
					break;
			case 3:	cdisplay(&q);
					break;		
			case 4: exit(0);
						
			default: printf("invalid choice\n");			
		}		
	}while(1);
return 0;
}

void cenque(queue *q ,int v)
{
	if(cisfull(q))
	{
		printf("circular queue is full\n");
		return ;
	}
	if(q->f==-1)
		q->f=0;
	q->r=++(q->r)%size;
	q->a[q->r]=v;
	return;
}


int cdeque(queue *q)
{
	int p;
	if(cisempty(q))
	{
		printf("circular queue is underflow i.e deque operation is not perform\n");
		return -1;
	}
	p=q->a[q->f];
	if(q->f==q->r)
		q->f=q->r=-1;
	else
		q->f=((q->f+1)%size);
	return p;
}



//void cdisplay (queue *q)
//{
//	int i;
//	if(cisempty(q))
//	{
//		printf("queue  is empty i.e under flow\n");
//		return ;
//	}
//	printf("element in queue is\n");
//	for(i=q->f;i<=q->r;i++)
//		printf("%d\n",q->a[i]);
//}

int cisempty(queue *q)
{
	if(q->f==-1)
	{
		return 1;
	}
	else 
		return 0;	
	
}

int cisfull(queue *q)
{
	if(q->f==0 && q->r==size-1 || q->f==q->r+1)
		return 1;
	else 
		return 0;
		
}


void cdisplay (queue *q)
{
	int i=q->f;
	if(cisempty(q))
	{
		printf("queue  is empty i.e under flow\n");
		return ;
	}
	printf("element in queue is\n");
	while(i!=q->r)
	{
		printf("%d\n",q->a[i]);
		i=(i+1)%size;
		
	}
	printf("%d\n",q->r);	
}
