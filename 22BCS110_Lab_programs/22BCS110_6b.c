#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} typedef qll;
qll *front = 0;
qll *rear = 0;
void enqueue(int element)
{
    qll *newnode;
    newnode = (qll *)malloc(sizeof(qll));
    newnode->data = element;
    newnode->link = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
    printf("%d is enqueued\n", rear->data);
}
void dequeue()
{
    qll *temp;
    temp = front;
    if (front == 0)
    {
        printf("Queue underflow!!\n");
    }
    else
    {
        front = front->link;
        printf("%d is dequeued\n", temp->data);
        free(temp);
    }
}
void peek()
{
    (front == 0) ? printf("Queue is empty!!\n") : printf("%d is on the top of the queue\n", front->data);
}
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        qll *temp;
        temp = front;
        printf("the elements in the queue are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
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