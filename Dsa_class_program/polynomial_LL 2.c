#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct Node 
{
    int c,e;
    struct Node *next ;
}node;

node* createnode(int c,int e);
void display(node *start);
node* createpoly(node *start);
int compute(node *start,int x);

int main() {
    int ch,x,v;
    node *start = NULL;

    printf("\n*** MENU OF polynomial ***\n");
    printf("1. createpoly\n2. display\n3.compute\n4.Exit\n");
    do 
    {
      printf("\nEnter your choice: ");
      scanf("%d", &ch);

      switch (ch) 
      {
            case 1:
                  start = createpoly(start);
                  break;
            case 2:
                  
                  display(start);
                  break; 
            case 3:
                  if(start==NULL)
                  {
                        printf("polynomial does not exit\n");
                  }
                  else
                  {
                        printf("enter the value of x=");
                        scanf("%d",&x);
                        v=compute(start,x);
                        printf("sum=%d",v);
                  }
      
                  break;
            case 4:
                  printf("Exiting...\n");
                  exit(0);
            default:
                  printf("Invalid choice\n");
      }
    } while (1);

return 0;
}

node* createnode(int c,int e) 
{
    node *nn = (node*)malloc(sizeof(node));
    if (nn == NULL) 
    {
        printf("Memory overflow or error\n");
        return NULL;
    }
    nn->c = c;
    nn->e=e;
    nn->next = NULL;
    return nn;
}

node* createpoly(node *start)
{
      node *nn,*p;
      int c,e,n,i=1;
      printf("enter no.of terms=");
      scanf("%d",&n);
      printf("REMEMBER...\npolynomial is in high degree to low .\n");
      while(i<=n)
      {
            printf("enter coefficient and exponent of the %d term :",i);
            scanf("%d%d",&c,&e);
            nn=createnode(c,e);
            if(start==NULL)
            {
                  start=nn;
                  p=start;
            }
            else
            {
                  p->next=nn;
                  p=nn;
            }
            i++;
      }
      return start;
}

void display(node *start)
{
      node *p;

      if(start==NULL)
      {
            printf("polynomial does not exist\n");
            return;
      }
      p=start;
      printf("polynomial expression :");
      while (p)
      {
            if (p != start && p->c >= 0)
            printf("+");

            if (p->e == 0) // constant term
                  printf("%d", p->c);
            else if (p->e == 1) // power 1
                  printf("%dx", p->c);
            else
                  printf("%dx^%d", p->c, p->e);

            p = p->next;
            // if(p==start || p->c< 0)
            // {
            //       printf("%dx^%d",p->c,p->e);
            // }
            // else
            //       printf("+%dx^%d",p->c,p->e);
            // p=p->next;
      }
      printf("\n");
}

int compute(node *start,int x)
{
      int sum=0;
      node *p=start;
      if(start==NULL)
      {
            printf("polynomial does not exist\n");
            return -1;
      }
      while(p)
      {
            sum = sum + p->c * (int) pow(x,p->e);
            p=p->next;
      }
      return sum;
}
