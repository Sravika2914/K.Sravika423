#include<stdio.h>
#include<ctype.h>
char stack[10];
int top;
void push(char x)
{
    stack[++top] = x;
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int pr(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
void main()
{
    char exp[20];
    char *q, x;
    top=-1;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    q = exp;
    while(*q != '\0')
    {
        if(isalnum(*q))
            printf("%c",*q);
        else if(*q == '(')
            push(*q);
        else if(*q == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(pr(stack[top]) >= pr(*q))
                printf("%c",pop());
            push(*q);
        }
        q++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}