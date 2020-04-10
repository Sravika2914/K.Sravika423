#include <stdio.h>
#include <string.h>
#define max 100	
int top=-1;
int n;
char stack_string[max];
void push(char n);
char pop(void);
int isEmpty(void);
int isFull(void);

void push(char n)
{
    if(isFull())
    {
        printf("\nStack is full\n");
        return;
    }
    top=top+1;
    stack_string[top]=n;
}
 char pop()
{
    if(isEmpty())
    {
        printf("\nstack is empty\n");
        return 0;
    }
    n = stack_string[top];
    top=top-1;
    return n;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}

int main()
{
    char str[max];
    
    int i;
    
    printf("Input a string: ");
    scanf("%[^\n]s",str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
        
    for(i=0;i<strlen(str);i++)
        str[i]=pop();

    printf("Reversed String is: %s\n",str);
    
    return 0;
}