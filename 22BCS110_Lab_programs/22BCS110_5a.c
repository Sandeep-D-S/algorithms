#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int deque[MAXSIZE];
int front = -1;
int rear = -1;
void insertFront(int element)
{
    if ((rear + 1) % MAXSIZE == front)
    {
        printf("Deque overflow!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = element;
        printf("%d is enqueued\n", deque[front]);
    }
    else if (front == 0)
    {
        front = MAXSIZE - 1;
        deque[front] = element;
        printf("%d is enqueued\n", deque[front]);
    }
    else
    {
        front--;
        deque[front] = element;
        printf("%d is enqueued\n", deque[front]);
    }
}
void insertRear(int element)
{
    if ((rear + 1) % MAXSIZE == front)
    {
        printf("Deque overflow!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = element;
        printf("%d is enqueued\n", deque[rear]);
    }
    else if (rear == MAXSIZE - 1)
    {
        rear = 0;
        deque[rear] = element;
        printf("%d is enqueued\n", deque[rear]);
    }
    else
    {
        rear++;
        deque[rear] = element;
        printf("%d is enqueued\n", deque[rear]);
    }
}
void deleteFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque underflow!!\n");
    }
    else if (front == rear)
    {
        printf("%d is dequeued\n", deque[front]);
        front = rear = -1;
    }
    else if (front == MAXSIZE - 1)
    {
        printf("%d is dequeued\n", deque[front]);
        front = 0;
    }
    else
    {
        printf("%d is dequeued\n", deque[front]);
        front++;
    }
}
void deleteRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque underflow!!\n");
    }
    else if (front == rear)
    {
        printf("%d is dequeued\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("%d is dequeued\n", deque[rear]);
        rear = MAXSIZE - 1;
    }
    else
    {
        printf("%d is dequeued\n", deque[rear]);
        rear--;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is empty!!\n");
    }
    else
    {
        int i = front;
        printf("The elements in the deque are:\n");
        while (i != rear)
        {
            printf("%d\t", deque[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d\n", deque[i]);
    }
}
int main()
{
    int choice, element;
    while (1)
    {
        printf("The operations available are:\n1.insertFront\n2.insertRear\n3.deleteFront\n4.deleteRear\n5.Display\n6.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &element);
            insertFront(element);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &element);
            insertRear(element);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid selection!!\n");
            break;
        }
    }
}