#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top = -1;
void push(int element);
int pop();
int peek();
void display();
int main()
{
    int choice, element;
    do
    {
        printf("Stack operations are:\n1.push\n2.pop\n3.peek\n4.display\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            printf("\n%d is popped from the stack\n", element);
            break;
        case 3:
            element = peek();
            printf("%d is on the top of the stack\n", element);
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid selection!!\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
void push(int element)
{
    if (top == MAXSIZE - 1)
    {
        printf("Stack overflow!!\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d is pushed into the stack\n", stack[top]);
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Stack underflow!!\n");
        exit(1);
    }
    else
    {
        int element = stack[top];
        top--;
        return element;
    }
}
int peek()
{
    if (top == -1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        int element = stack[top];
        return element;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i > -1; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}