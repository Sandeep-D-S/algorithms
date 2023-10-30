#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int rear = -1;
int front = -1;
void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
        printf("%d is enqueued into the queue\n", queue[rear]);
    }
    else if ((rear + 1) % MAXSIZE == front)
    {
        printf("Queue overflow!!\n");
    }
    else
    {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = element;
        printf("%d is enqueued into the queue\n", queue[rear]);
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow!!\n");
    }
    else if (front == rear)
    {
        printf("%d is dequeued from the queue\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is dequeued from the queue\n", queue[front]);
        front = (front + 1) % MAXSIZE;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        int i = front;
        printf("The elements in the queue are:\n");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % MAXSIZE;
        };
        printf("%d\n", queue[rear]);
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        printf("%d is on the top of the queue\n", queue[front]);
    }
}
void main()
{
    int choice, element;
    while (1)
    {
        printf("The operations available are:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid selection!!\n");
            break;
        }
    }
}