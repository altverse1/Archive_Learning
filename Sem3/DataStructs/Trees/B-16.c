// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left, *right;
    int info;
} node;

node *getnode(int data)
{
    node *new = NULL;
    new = (node *)malloc(sizeof(node));
    new->info = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void insert(node **root, int data)
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
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}

node *research(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data == root->info)
    {
        return root;
    }
    if (data < root->info)
    {
        return research(root->left, data);
    }
    else
    {
        return research(root->right, data);
    }
}

node *maxvalue(node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

int main()
{
    node *root = NULL;
    int ch, x;
    while (1)
    {
        printf("\n1.Insert 2.Inorder 3.Search 4.MaxValue 5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Value:");
            scanf("%d", &x);
            insert(&root, x);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter Value:");
            scanf("%d", &x);
            node *cur = research(root, x);
            if (cur == NULL)
            {
                printf("Not Found");
                break;
            }
            printf("Found!");
            break;
        case 4:
            printf("\n");
            node *max = maxvalue(root);
            if(max==NULL)
                printf("Empty Tree\n");
            else
                printf("Max is: %d", max->info);
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}