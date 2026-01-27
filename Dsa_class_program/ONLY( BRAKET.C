#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
typedef struct Stack {
    char stack[SIZE];
    int top;
} stack;

void push(stack *s, char op) {
    if (s->top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->stack[++(s->top)] = op;
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0' ;
    }
    return s->stack[(s->top)--];
}

int paren_checker(char str[]) {
    stack s;
    s.top = -1;
    int i = 0;
    char op ;

    while (str[i] != '\0') 
	{
//		ch = str[i];
        if (str[i]== '(' )
 
            push(&s, str[i]);
    	
        else if (str[i] == ')') 
		{
            if (s.top != -1)
            {
            	op = pop(&s);
			}
            else
                return 0; 
        }
        i++;
    }
    return (s.top == -1); 
}

int main() {
    char str[SIZE];
    int res;
    do
    {
    	printf("*** CHECK BRACKET PARENTHESIS ***\n");
    
    	printf("Enter the braces: ");
    	scanf("%s", str);
		res=(paren_checker(str));
    	if (res)
    	    printf("Valid expression\n");
    	else
    	    printf("Invalid expression\n");

    
	}while(1);
    return 0;
}

