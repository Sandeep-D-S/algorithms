#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *last = NULL;
void insertAtBegin(int element){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = element;
    if (start == NULL){
        start = last = newNode;
    }else{
        newNode->next = start;
        start = newNode;
    }
    last->next = start;
    printf("%d is added\n", start->data);
}
void insertAtEnd(int element){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    if(start == NULL){
        start = last = newNode;
        last->next = start;
    }else{
        newNode->next = start;
        last->next = newNode;
        last = newNode;
    }
    printf("%d is added\n",last->data);
}
void insertAtPos(int element, int pos){
    struct node *temp, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    temp = start;
    for(int i = 1;i <= pos-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d is added after %d position\n",temp->next->data,pos);
}
void deleteAtBegin(){
    struct node *temp;
    if(start == NULL){
        printf("Underflow condition!!\n");
        exit(0);
    }else{
        temp = start;
        start = start->next;
        last->next = start;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void deleteAtEnd(){
    struct node *temp, *prev;
    if(start == NULL){
        printf("Underflow condition!!\n");
        exit(0);
    }else{
        temp = start;
        while(temp != last){
            prev = temp;
            temp = temp->next;
        }
        last = prev;
        last->next = start;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void deleteAtPos(int pos){
    struct node *temp, *prev;
    temp = start;
    for(int i = 1;i <= pos-1;i++){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("%d is deleted at %d position\n",temp->data,pos);
    free(temp);
}
void display(){
    if(start == NULL){
        printf("linked list is empty!!\n");
        exit(0);
    }else{
        struct node *i;
        printf("the elements in the list are:\n");
        for(i = start; i->next != start;i = i->next){
            printf("%d\t",i->data);
        }
        printf("%d\n",i->data);
    }
}
int main(){
    int choice, element, pos;
    while(1){
        printf("the operations available are:\n");
        printf("1.insertAtBegin\n2.insertAtEnd\n3.insetAtPos\n4.deleteAtBegin\n5.deleteAtEnd\n6.deleteAtPos\n7.display\n8.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            insertAtBegin(element);
            break;
        case 2:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            insertAtEnd(element);
            break;
        case 3:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            insertAtPos(element, pos);
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            deleteAtPos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Selection!!\n");
            break;
        }
    }
}