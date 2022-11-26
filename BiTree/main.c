#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define COUNT 5
typedef int type;
typedef struct Node 
{
    type data;
    struct Node* left;
    struct Node* right;
    
} Node;

Node* createNode(type val)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;     
}
void displayTree(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    displayTree(root->left);
    printf("%d>\n", root->data);
    displayTree(root->right);
}
Node* AddNode(Node* node, type val)
{
    if (node == NULL)
    {
        return(createNode(val));
    }
    if (val < node->data)
    {
        node->left = AddNode(node->left, val);
    } 
    else if (val > node->data)
    {
        node->right = AddNode(node->right, val);
    }
    return node;
    
}
void printAll(struct Node* root, int space)
{

    if (root == NULL)
    {
        printf("EMpty\n");
        return;
    }
    space += COUNT;
    printAll(root->right, space);
    printf(" ");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d <\n", root->data);
    printAll(root->left, space);
}
Node* Search(Node *node, type val)
{
    if (node == NULL)
    {
        printf("Empty!!!\n");
        return NULL;
    }
    if (val == node->data)
    {
        return node;
    }
    else if (val < node->data)
    {
        Search(node->left, val);
    } 
    else if (val > node->data)
    {
        Search(node->right, val);
    }
}
void Delete(Node* root)
{
    if (root == NULL) 
    {
        printf("Empty!!!\n");
        return;
    }else
    {
        Delete(root->left);
        Delete(root->right);
        free(root);
    }
}
Node *root = NULL;
void main()
{
    Delete(root);
}