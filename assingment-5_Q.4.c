#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int value; 
    struct node *left, *right; 
};
struct node *newNode(int n) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->value = n; 
    temp->left = temp->right = NULL; 
    return temp; 
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->value); 
        inorder(root->right); 
    } 
} 
struct node* insert(struct node* node, int value) 
{ 
    if (node == NULL)
    return newNode(value); 
    if (value < node->value) 
        node->left  = insert(node->left, value); 
    else
        node->right = insert(node->right, value); 
    return node; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct node* deleteNode(struct node* root, int value) 
{
    if (root == NULL) return root; 
    if (value < root->value) 
        root->left = deleteNode(root->left, value); 
    else if (value > root->value) 
        root->right = deleteNode(root->right, value); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->value = temp->value; 
        root->right = deleteNode(root->right, temp->value); 
    } 
    return root; 
} 
void main() 
{ 
   struct node *root = NULL; 
    root = insert(root, 15); 
    root = insert(root, 18); 
    root = insert(root, 14); 
    root = insert(root, 11); 
    root = insert(root, 49); 
    root = insert(root, 54); 
    root = insert(root, 75); 
    root = insert(root, 01); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
    
    printf("\nDelete 02\n"); 
    root = deleteNode(root, 02); 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
    
    printf("\nDelete 14\n"); 
    root = deleteNode(root, 14); 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 08\n"); 
    root = deleteNode(root, 18); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 01\n"); 
    root = deleteNode(root, 01); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
}
