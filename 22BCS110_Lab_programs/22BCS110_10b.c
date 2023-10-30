#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node* create(){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the data: ");
    scanf("%d",&x);
    newNode->data = x;
    if(x == -1)
        return 0;
    printf("Enter the left child of the %d: ",x);
    newNode->left = create();
    printf("Enter the right child of the %d: ",x);
    newNode->right = create();
    return newNode;
}
void preOrder(struct node *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct node *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
void main(){
    struct node *root = NULL;
    root = create();
    printf("\nPre order: ");
    preOrder(root);
    printf("\nIn order: ");
    inOrder(root);
    printf("\nPost order: ");
    postOrder(root);
}