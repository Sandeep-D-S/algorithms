#include <stdio.h>
#include <stdlib.h>
struct lifo
{
    int data;
    struct lifo *link;
};
struct lifo *start = NULL;
void push(int element)
{
    struct lifo *newnode;
    newnode = (struct lifo *)malloc(sizeof(struct lifo));
    newnode->data = element;
    newnode->link = start;
    start = newnode;
    printf("%d is pushed into the stack\n", newnode->data);
}
void pop()
{
    struct lifo *temp;
    if (start == NULL)
    {
        printf("Stack underflow!!\n");
    }
    temp = start;
    start = start->link;
    printf("%d is popped from the stack\n", temp->data);
    free(temp);
}
void peek()
{
    if (start == NULL)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("%d is on the top of the stack\n", start->data);
    }
}
void display()
{
    struct lifo *temp;
    temp = start;
    if (start == NULL)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("the elements present in the stack are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
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
            pop();
            break;
        case 3:
            peek();
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