#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int power;
    struct Node *next;
};
struct Node *createNode(int coeff, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}
void addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *tail = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            int coeff_sum = poly1->coeff + poly2->coeff;
            if (coeff_sum != 0)
            {
                struct Node *newNode = createNode(coeff_sum, poly1->power);
                if (result == NULL)
                {
                    result = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power)
        {
            struct Node *newNode = createNode(poly1->coeff, poly1->power);
            if (result == NULL)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            poly1 = poly1->next;
        }
        else
        {
            struct Node *newNode = createNode(poly2->coeff, poly2->power);
            if (result == NULL)
            {
                result = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        struct Node *newNode = createNode(poly1->coeff, poly1->power);
        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        struct Node *newNode = createNode(poly2->coeff, poly2->power);
        if (result == NULL)
        {
            result = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        poly2 = poly2->next;
    }
    printf("Result: ");
    struct Node *temp = result;
    while (temp != NULL)
    {
        printf("%dX^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
}
int main()
{
    struct Node *poly1 = createNode(2, 3);
    poly1->next = createNode(3, 2);
    poly1->next->next = createNode(1, 0);
    struct Node *poly2 = createNode(1, 3);
    poly2->next = createNode(2, 2);
    poly2->next->next = createNode(4, 1);
    addPolynomials(poly1, poly2);
    return 0;
}
