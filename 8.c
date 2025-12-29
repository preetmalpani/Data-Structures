#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int value){
    if(root==NULL){
        return create_node(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node* root = NULL;
    int n,value,i;
    printf("Enter the number of elements to insert: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&value);
        root = insert(root,value);
    }
    printf("\nBST traversals\n");
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
}

OUTPUT:
Enter the number of elements to insert: 6
Enter element 1: 10
Enter element 2: 15
Enter element 3: 45
Enter element 4: 60
Enter element 5: 20
Enter element 6: 75

BST traversals

Inorder traversal: 10 15 20 45 60 75 
Preorder traversal: 10 15 45 20 60 75 
Postorder traversal: 20 75 60 45 15 10 
