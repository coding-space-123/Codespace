#include <stdio.h>
#include <stdlib.h>
#define SIZE 100  

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

char peek(stack s) {
    if (s.top == -1)
        return '\0';
    return s.stack[s.top];
}

int paren_checker(char str[]) {
    stack s;
    s.top = -1;
    int i = 0;
    char op;

    while (str[i] != '\0') {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        }
        else if ((str[i] == ')' && peek(s) == '(') ||
                 (str[i] == '}' && peek(s) == '{') ||
                 (str[i] == ']' && peek(s) == '[')) {
            if (s.top == -1)
                return 0;   
            op = pop(&s);   
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            return 0;      
        }
        i++;
    }
    return (s.top == -1); 
}

int main() {
    char str[SIZE];
    int res;
    do {
        printf("\n*** CHECK BRACKET PARENTHESIS ***\n");
        printf("Enter the braces: ");
        scanf("%s", str);

        res = paren_checker(str);
        if (res)
            printf("Valid expression\n");
        else
            printf("Invalid expression\n");

    } while (1);

    return 0;
}

