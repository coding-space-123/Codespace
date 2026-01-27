#include<stdio.h>
int linear_search(int a[],int n,int s)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==s)
            return i;
    }
    return -1;
}
int main()
{
    int a[]={2,1,7,9,4,13},s,i,v;
    int n= sizeof(a)/sizeof(a[0]);
    printf("enetr the value to be searched=");
    scanf("%d",&s);
    v=linear_search(a,n,s);
    if(v != -1)
        printf("element is found\n at index %d",v);
    else
        printf("element is not found\n");
    return 0;

}