//Singly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *next;
    int data;
} node;

void insert_front(node **head)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    printf("Enter Element: ");
    scanf("%d", &temp->data);
    printf("\n");
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

int delete_rear(node **head)
{
    int value;
    if (*head == NULL)
    {
        printf("The List is empty\n");
        value = -1;
    }
    else if ((*head)->next == NULL)
    {
        value = (*head)->data;
        free(*head);
        *head = NULL;
    }
    else
    {
        node *ptr, *preptr;
        ptr = *head;
        while (ptr->next != NULL)
        {
            preptr=ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        preptr->next=NULL;
        free(ptr);
    }
    return value;
}


void display(node **head)
{
    if (*head == NULL)
    {
        printf("The List is empty\n");
    }
    else
    {
        node *ptr;
        ptr = *head;
        while(ptr->next!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n\n",ptr->data);
    }
}

int main()
{
    node *head = NULL;
    int choice;
    while (1)
    {
        printf("Enter The Option: 1)Front Insert 2)Delete Rear 3)Display 4)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front(&head);
            break;
        case 2:
            printf("%d\n", delete_rear(&head));
            break;
        case 3:
            display(&head);
            break;
        case 4:
            exit(0);
        default:
            printf("Something is not right\n");
            break;
        }
    }
    return 0;
}