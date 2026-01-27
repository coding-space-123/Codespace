#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

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
        return '\0';
    }
    return s->stack[(s->top)--];
}

int paren_checker(char str[]) {
    stack s;
    s.top = -1;
    int i = 0;
    char op ,ch;

    while (str[i] != '\0') 
	{
		ch = str[i];
        if (ch == '(' || ch== '{' || ch== '[')
 
            push(&s, str[i]);
    	
        else if (ch == ')'|| ch== '}' || ch== ']') 
		{
            if (s.top != -1)
            {
            	op = pop(&s);
                
                if ((op == '(' && ch != ')') ||
    				(op == '{' && ch != '}') ||
    				(op == '[' && ch != ']'))
    					return 0; 
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

