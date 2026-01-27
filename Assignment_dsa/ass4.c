#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>


#define SIZE 100

typedef struct Stack {
    int top;
    char opt_stack[SIZE];
} stack;

void push(stack *s, char v) ;
char pop(stack *s);
char peek(stack s);
void intoprefix(char infix[], char prefix[]) ;
void reverse(char str[]);
int precedence(char ch);
int isempty(stack s);
void intopostfix(char infix[SIZE], char postfix[SIZE]);


int main() {
    char infix[SIZE], prefix[SIZE];
    do
    {
        printf("Enter valid infix expression: ");
    	scanf("%s", infix);
    	intoprefix(infix, prefix);
    	printf("Prefix expression: %s\n", prefix);
    }while(1);
    	
    	

return 0;
}


void push(stack *s, char v) {
    s->opt_stack[++s->top] = v;
}

char pop(stack *s) {
    return s->opt_stack[s->top--];
}

char peek(stack s) {
    return s.opt_stack[s.top];
}

int isempty(stack s) {
    return s.top == -1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

void intopostfix(char infix[SIZE], char postfix[SIZE]) {
    stack s;
    s.top = -1;
    int i = 0, j = 0;
    char opt;
    while (infix[i] != '\0') 
	{
        if (isalnum(infix[i])) 
            postfix[j++] = infix[i];
            
        else if (infix[i] == '(' || isempty(s)) 
            push(&s, infix[i]);
        else if (infix[i] == ')') 
		{
            while (peek(s) != '(') 
                postfix[j++] = pop(&s);
            opt = pop(&s);
        } 
		else { 
            while (!isempty(s) && precedence(infix[i]) <= precedence(peek(s))) 
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }
        i++;
    }
    while (!isempty(s)) 
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

void reverse(char str[]) {
    int len = strlen(str);
    int i ;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void intoprefix(char infix[], char prefix[]) 
{
    char revinfix[SIZE], postfix[SIZE];
    int i ;
    strcpy(revinfix, infix);
    reverse(revinfix);

    for (i= 0; revinfix[i] != '\0'; i++) 
	{
        if (revinfix[i] == '(') revinfix[i] = ')';
        else if (revinfix[i] == ')') 
		revinfix[i] = '(';
    }

    intopostfix(revinfix, postfix);

    strcpy(prefix, postfix);
    reverse(prefix);
}






