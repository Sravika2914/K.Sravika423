#include <stdio.h>
#include <stdlib.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
int stack1[50], stack2[50];
int top1,top2;
int count=0;
void create()
{
    top1 =-1;
    top2 =-1;
}
void push1(int value)
{
    stack1[++top1] = value;
}
int pop1()
{
    return(stack1[top1--]); 
}
void push2(int value)
{
    stack2[++top2] = value; 
}
int pop2()
{
    return(stack2[top2--]);
}
void enqueue()
{
    int num, i;
    printf("Enter the value : ");
    scanf("%d", &num);
    push1(num); 
    count++;
}
void dequeue()
{
    int i;
    for (i = 0;i <= count;i++)
    {
        push2(pop1()); 
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2()); 
    }}
void display()
{
    int i;
    if(top1 == -1)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\nqueue elements are : ");
        for (i = 0;i <= top1;i++)
        {
            printf(" %d ", stack1[i]);
        }
        printf("\n");
}}
int main()
{
    int ch;
    printf("Enter choice 1-enqueue,2-dequeue,3 for display and 4 for exit\n");
    create();
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }
    
}
