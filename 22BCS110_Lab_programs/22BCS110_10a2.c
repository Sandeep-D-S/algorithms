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
void inorder(struct node *root){
    if(root == 0)   
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
struct node* deleteBST(struct node *root, int value){
    if(root == NULL)
        return root;
    if(value < root->data){
        root->left = deleteBST(root->left, value);
        return root;
    }else if(value > root->data){
        root->right = deleteBST(root->right, value);
        return root;
    }
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    if(root->left == NULL){
        temp = root->right;
        free(root);
        return temp;
    }else if(root->right == NULL){
        temp = root->left;
        free(root);
        return temp;
    }else{
        struct node *succParent = root;
        struct node *succ = root->right;
        while(succ->left != NULL){
            succParent = succ;
            succ = succ->left;
        }
        if(succParent != root)
            succParent->left = succ->right;
        else    
            succParent->right = succ->right;
        root->data = succ->data;
        free(succ);
        return root;
    }
}
int main(){
    struct node *root = NULL;
    int x;
    root = create();
    inorder(root);
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&x);
    root = deleteBST(root, x);
    inorder(root);
}