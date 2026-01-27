#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
	int data ;
	struct Node *next;
	
} node;

void rev_dis(node *start);
node* rev_list(node *start);
node* createnode(int v);
void displaylist(node* start);
node* deletion(node *start);
node* createlist(node *start);
void max_node (node *start);
void count_node(node *start);
void occur_node(node* start);

void main()
{
	int ch;
	node *start = NULL,*p;
    
      printf("\n*** MENU OF LINKED LIST ***\n");
      printf("1. Insert in sorted order\n2. Delete by value\n3. Display\n4.display reverse list\n5.reverse linked_list\n6.max_node\n7.count_nodes\n8.occurence of particular nodes\n9.Exit\n");
	do {
	  printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
            	    start = createlist(start);
            	    break;
            case 2:
            	    start = deletion(start);
            	    break;
            case 3:
            	    displaylist(start);
            	    break;
            case 4:
                rev_dis(start);
                break;
            case 5:
                start=rev_list(start);
                displaylist(start);
                break; 
		case 6:
			 max_node (start) ;
			 	break;
		case 7: count_node(start);
				break;
		case 8: occur_node(start);
				break;
            case 9:
            	    exit(0);
            	    break;
            default:
            	   printf("Invalid choice\n");
        }
    } while(1);


}

node* createnode(int v)
{
	node *nn;
	nn=(node*) malloc (sizeof(node));
	if(nn==NULL)
	{
		printf("memory overflow or error\n");
		return nn;
	}
	nn->data=v;
	nn->next=NULL;
	return nn;
}

node* createlist(node* start)
{
	node *nn = NULL, *p;
	char ch;
	int v;
	do
	{
		printf("enter the value for the node :");
		scanf("%d",&v);
		nn=createnode(v);
		if(start==NULL)
			start=nn;
		else
		{
			p=start;
			while(p->next!=NULL)
				p=p->next;
			p->next=nn;
		}
		printf("do you want add more node(y/n):");
		fflush(stdin);
		scanf("%c",&ch);
		
	}
	while(ch=='y' || ch=='Y');
return start;
}


void displaylist(node *start)
{
	node *p;
	if(start==NULL)
	{
		printf("list not exist\n");
		return;
	}
	p=start;
	printf("List: ");
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}

} 

node* deletion(node *start)
{
	node *temp,*p;
	int target;
	printf("enter the value to be deleted:");
	scanf("%d",&target);
	if(start==NULL)
	{
		printf("list not exist\n");
		return start;
	}
	else if(start->data==target)
	{
		temp =start;
		start=start->next;
		printf("deleted value %d",target);
		free(temp);
		return start;
	}
	p=start;
	while(p->next != NULL && p->next->data != target)
		p=p->next;
	if(p->next != NULL)
	{
		temp=p->next;
		p->next=p->next->next;
		printf("deleted value %d",target);
		free(temp);
		return start;
	}
	else 
		printf("target value not found\n");
return start;
}

void rev_dis(node *start)
{
    node *p =start;
    if(p==NULL)
        return;
    rev_dis(p->next);
    printf("%d\t",p->data);

}

node* rev_list(node *start)
{
    node *p=NULL,*c=start,*n;
    while(c != NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}

void max_node(node *start) {
	if (start == NULL) {
	    printf("List does not exist\n");
	    return ;  
	}
  
	int max = start->data; 
	node *p = start->next;
  
	while (p) {
	    if (p->data > max) {
		  max = p->data;
	    }
	    p = p->next;
	}
  
	printf("max node= %d\n",max);
  }
  

  void count_node(node *start)
  {
	if (start == NULL) {
		printf("List does not exist\n");
		return ;  
	  }
    
	  int count= 0; 
	  node *p = start;
    
	  while (p) {
		
		count++;
		
		p = p->next;
	  }
    
	  printf("count node= %d",count);
  }
  void occur_node(node* start) {
	if (start == NULL) {
	    printf("List does not exist\n");
	    return;
	}
  
	int val, count = 0;
	printf("Enter value to find occurrences: ");
	scanf("%d", &val);
  
	node* p = start;
	while (p) {
	    if (p->data == val) { 
		  count++;
	    }
	    p = p->next;
	}
  
	if (count > 0)
	    printf("Value %d occurs %d time(s) in the list.\n", val, count);
	else
	    printf("Value %d does not occur in the list.\n", val);
  }
  

