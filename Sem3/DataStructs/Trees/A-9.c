// Expression Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

typedef struct NODE
{
    struct NODE *left;
    int info;
    struct NODE *right;
} node;

node *construct_tree(char postfix[])
{
    // initialize
    if (postfix[0] == '\0')
        return NULL;
    char sym;
    int i, top = -1;
    node *new, *stack[MAX];
    // select and work on each symbol
    for (i = 0; postfix[i] != '\0'; i++)
    {
        // create a new node
        sym = postfix[i];
        new = (node *)malloc(sizeof(node));
        new->info = sym;
        new->left = NULL;
        new->right = NULL;

        if (isdigit(sym)) // if digit store directly in stack
        {
            stack[++top] = new;
        }
        else
        {
            switch (sym) // if operator then pull two digits
            {            // then put them in right and left then push node into stack
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                new->right = stack[top--];
                new->left = stack[top--];
                stack[++top] = new;
                break;

            default:
                return NULL;
                break;
            }
        }
    }
    return stack[top--];
}

int evaluate(node *root)
{
    switch (root->info)
    {
    case '+':return(evaluate(root->left)+evaluate(root->right));
    case '-':return(evaluate(root->left)-evaluate(root->right));
    case '*':return(evaluate(root->left)*evaluate(root->right));
    case '/':return(evaluate(root->left)/evaluate(root->right));
    case '^':return(pow(evaluate(root->left),evaluate(root->right)));

    default:
        return(root->info-'0');
    }
}

int main()
{
    int result;
    char postfix[MAX];
    node *root = NULL;
    printf("Enter the expression: \n");
    gets(postfix);
    root = construct_tree(postfix);
    if (root == NULL)
    {
        printf("Some Error\n");
        return 0;
    }
    result = evaluate(root);
    printf("The Evaluation: %d\n",result);
    return 0;
}