#include <stdio.h>
int main()
{
    int num, size, arr[20];
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *parr, *pnum;
    printf("Enter the num: ");
    scanf("%d", &num);
    pnum = &num;
    parr = arr;
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the %d element: ", i);
        scanf("%d", (parr + i));
    }
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (*(parr + i) + *(parr + j) == *pnum)
            {
                printf("(%d,%d)", *(parr + i), *(parr + j));
            }
        }
    }
}