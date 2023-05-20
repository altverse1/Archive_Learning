// Binary Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    int info;
    struct NODE *right;
} node;

node *getnode(int data)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void create_tree(node **root, int data)
{
    if (*root == NULL)
    {
        *root = getnode(data);
        return;
    }
    if ((*root)->info == data)
    {
        return;
    }
    if ((*root)->info > data)
    {
        create_tree(&((*root)->left), data);
    }
    else
    {
        create_tree(&((*root)->right), data);
    }
}

void pre_order(node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d\n", root->info);
        in_order(root->right);
    }
}

void post_order(node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d\n", root->info);
    }
}

int main()
{
    int choice, data;
    printf("Creating Binary Tree\n");
    node *root;
    root = NULL;
    while (1)
    {
        printf("1)Insert 2)Preorder 3)Inorder 4)Postorder 5)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &data);
            create_tree(&root, data);
            break;
        case 2:
            printf("\n\n----Displaying Pre Order----\n\n");
            pre_order(root);
            printf("\n\n");
            break;
        case 3:
            printf("\n\n----Displaying In Order----\n\n");
            in_order(root);
            printf("\n\n");
            break;
        case 4:
            printf("\n\n----Displaying Post Order----\n\n");
            post_order(root);
            printf("\n\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Unrecognized");
            break;
            
        }
    }
    return 0;
}