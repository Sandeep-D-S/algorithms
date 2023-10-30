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
        return 0;
    }
    printf("Enter the left child of %d: ",temp);
    newNode->left = create();
    printf("Enter the right child of the %d: ",temp);
    newNode->right = create();
    return newNode;
}
int searchBST(struct node *root,int value){
    if(root == NULL)
        return 0;
    if(root->data == value)
        return 1;
    else{
        if(value < root->data)
            searchBST(root->left, value);
        else
            searchBST(root->right, value);
    }
}
int main(){
    struct node *root = NULL;
    root = create();
    int key,res;
    printf("Enter the value to be searched: ");
    scanf("%d",&key);
    res = searchBST(root, key);
    if(res)
        printf("The value has been found in the tree :)");
    else
        printf("The element is not found :(");
}