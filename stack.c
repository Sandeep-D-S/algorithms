#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
void push();
void pop();
void display();
void peek();
int stack[maxsize], top, opt;
int main()
{
    top = -1;
    while (1)
    {
        printf("Stack Operations available are:\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter the operation to be performed: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid Selection!!\n");
            break;
        }
    }
    return 0;
}
void push()
{
    if (top > maxsize - 1)
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        printf("Enter the element to be added: ");
        top++;
        scanf("%d", &stack[top]);
    }
}
void pop()
{
    if (top < 0)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("The element which is popped is %d\n", stack[top]);
        top--;
    }
}
void peek()
{
    if (top < 0)
    {
        printf("The element cannot be printed!! Stack Underflow!!\n");
    }
    else
    {
        printf("The element which is present in the top is %d\n", stack[top]);
    }
}
void display()
{
    if (top < 0)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("The elements present in the stack are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}