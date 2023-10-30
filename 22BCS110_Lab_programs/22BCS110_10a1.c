#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* create(){
    struct node *newNode;
    int temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data (-1 for NULL): ");
    scanf("%d",&temp);
    newNode->data = temp;
    if(temp == -1){
        return NULL;
    }
    printf("Enter the left child of %d: ",temp);
    newNode->left = create();
    printf("Enter the right child of the %d: ",temp);
    newNode->right = create();
    return newNode;
}
struct node *insertBST(struct node *root, int value){
    if(root == NULL){
        struct node *newNode;
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }else{
        if(value < root->data)
            root->left = insertBST(root->left, value);
        else if(value > root->data)
            root->right = insertBST(root->right, value);
        else{
            printf("Duplicate Entries are not allowed!!");
            exit(0);
        }
    }
}
void inorder(struct node *root){
    if(root == 0)   
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    struct node *root = NULL;
    root = create();
    while(1){
        int x;
        printf("enter the data: ");
        scanf("%d",&x);
        if(x == -1)
            break;
        root = insertBST(root, x);
    }
    inorder(root);
}