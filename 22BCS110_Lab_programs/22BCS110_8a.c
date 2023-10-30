#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *last = NULL;
void insert_at_begin(int element){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->prev = NULL;
    if(start == NULL){
        start = last = newNode;
        newNode->next = NULL;
        printf("%d is added\n",start->data);
    }else{
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
        printf("%d is added\n",start->data);
    }
}
void insert_at_end(int element){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = element;
    newNode->next = NULL;
    if(start == NULL){
        start = last = newNode;
        newNode->prev = NULL;
        printf("%d is added\n",last->data);
    }else{
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        printf("%d is added\n",last->data);
    }
}
void insert_at_pos(int element, int pos){
    struct node *temp, *newNode, *temp2;
    newNode = (struct node*)malloc(sizeof(struct node));
    int count = 0;
    temp2 = start;
    newNode->data = element;
    while(temp2 != NULL){
        temp2 = temp2->next;
        count++;
    }
    if((pos < 0) || (pos > count)){
        printf("Invalid position!!\n");
        exit(0);
    }else{
        struct node *adjacentNode;
        temp = start;
        adjacentNode = start;
        for(int i = 1;i <= pos-1;i++){
            temp = temp->next;
        }
        adjacentNode = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next = adjacentNode;
        adjacentNode->prev = newNode;
        printf("%d is added after %d node\n",newNode->data,pos);
    }
}
void delete_at_begin(){
    struct node *temp;
    if(start == NULL){
        printf("underflow condition!!\n");
        exit(0);
    }else{
        temp = start;
        start = start->next;
        start->prev = NULL;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void delete_at_end(){
    struct node *temp;
    if(last == NULL){
        printf("underflow condition!!\n");
        exit(0);
    }else{
        temp = last;
        last = last->prev;
        last->next = NULL;
        printf("%d is delted\n",temp->data);
        free(temp);
    }
}
void delete_at_pos(int pos){
    struct node *temp, *adjNext, *adjPrev,*temp2;
    int count = 0;
    temp2 = start;
    while(temp2 != NULL){
        temp2 = temp2->next;
        count++;
    }
    if((pos < 0) || (pos > count)){
        printf("Invalid position!!\n");
        exit(0);
    }else{
        temp = start;
        for(int i = 1;i <= pos-1;i++){
            temp = temp->next;
        }
        adjPrev = temp->prev;
        adjNext = temp->next;
        adjPrev->next = adjNext;
        adjNext->prev = adjPrev;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void display(){
    if(start == NULL){
        printf("linked lsit is empty!!\n");
        exit(0);
    }else{
        printf("data elements in the list are:\n");
        for(struct node *i = start;i != NULL;i = i->next){
            printf("%d\t",i->data);
        }
        printf("\n");
    }
}
int main(){
    int choice,element,pos;
    while(1){
        printf("The operations available in linked list are:\n");
        printf("1.insertAtBegin\n2.insertAtEnd\n3.insertAtPos\n4.deleteAtBegin\n5.deleteAtEnd\n6.deleteAtPos\n7.Display\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            insert_at_begin(element);
            break;
        case 2:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            insert_at_end(element);
            break;
        case 3:
            printf("\nEnter the data: ");
            scanf("%d",&element);
            printf("\nEnter the valid position: ");
            scanf("%d",&pos);
            insert_at_pos(element, pos);
            break;
        case 4:
            delete_at_begin();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            printf("\nEnter the valid position: ");
            scanf("%d",&pos);
            delete_at_pos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nInvalid selection!!");
            break;
        }
    }
}