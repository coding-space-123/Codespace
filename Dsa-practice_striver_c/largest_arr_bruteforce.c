//largets element in an array
//brute force approach : TC=O(nlogn) SC=O(1)
#include<stdio.h>
#define size 3
void main()
{   
    int a[]={3,2,1,5,2};
    int n= sizeof(a) / sizeof(a[0]);
    int i,j,temp,largest,second_l,flag=0;
    
    printf("sorted data:\t");
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
       printf("%d\t",a[i]);
    printf("\nlargest element is %d\n",a[n-1]);
    for(i=n-2;i>=0;i--)
    {
        if(a[i] != largest)
        {
            flag=1;
            second_l=a[i];
            break;
        }
    }
    if(flag==1)
    {
        printf("\n second largest element is %d\n",second_l);  
        return ;
    }    
    printf("second largest element does not exit\n");   
return ;
}   
//  better approach TC=O(2n)
// for (i = 0; i < n; i++) {
//     if (a[i] != largest && a[i] > second_l) {
//         second_l = a[i];
//         flag = 1;
//     }
// }


// if (flag)
//     printf("\nSecond largest element is %d\n", second_l);
// else
//     printf("Second largest element does not exist\n");

      
// return ;
// }

