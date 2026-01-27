#include<stdio.h>


struct stack {
    int size=10;
    int top=-1;  //stack empty
    int * arr; //by this ptr ,allocate memory dynamically 
}
int main()
{
    struct stack s;
    s.size=10;
    s.top=-1;  //stack empty
    s.arr= (int *) malloc (s.size * sizeof(int));

    return 0;
}