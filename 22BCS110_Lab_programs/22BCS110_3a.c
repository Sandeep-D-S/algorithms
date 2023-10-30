#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (rear == MAXSIZE - 1)
    {
        printf("Queue overflow!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
        printf("%d is enqueued into the queue\n", queue[rear]);
    }
    else
    {
        rear++;
        queue[rear] = element;
        printf("%d is enqueued into the queue\n", queue[rear]);
    }
}
void dequeue()
{
    if (front == -1)
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
        front++;
    }
}
void peek()
{
    if (front == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        printf("%d is in the peek of the queue\n", queue[front]);
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        int i = front;
        printf("The elements in the queue are:\n");
        while (i <= rear)
        {
            printf("%d\t", queue[i]);
            i++;
        }
        printf("\n");
    }
}
void isFull()
{
    (rear == MAXSIZE - 1) ? printf("Queue is full!!\n") : printf("Queue is not full!!\n");
}
void main()
{
    int choice, element;
    while (1)
    {
        printf("The operations available are:\n1.enqueue\n2.dequeue\n3.peek\n4.display\n5.isFull\n6.exit\n");
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
            isFull();
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