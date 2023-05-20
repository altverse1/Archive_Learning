//Queue Using STRUCTURE

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct QUEUE
{
    int first;
    int data[MAX];
    int last;
}queue;

void insert(queue*q, int a)
{
    if(q->last==MAX-1)
    {
        printf("Queue Full\n");
    }
    else
    {
        if(q->first==-1)
            q->first++;
        q->data[q->last]=a;
        q->last++;
    }
}

int delete(queue*q)
{
    if((q->first == -1)||(q->first==q->last))
    {
        printf("This is empty\n");
        return -1;
    }
    else
    {
       int temp = q->data[q->first];
       q->first++;
       return temp;
    }
}

void display(queue*q)
{
    if ((q->first == -1)||(q->first==q->last))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Printing the queue\n||");
        for (int i = q->first; i < q->last; i++)
            printf("%d ", q->data[i]);
        printf("||\n");
    }
}

int main()
{
    queue s;
    s.first = -1;
    s.last = 0;
    int choice, num;
    while (1)
    {
        printf("Enter your choice: 1)Insert 2)Delete 3)Display 4)Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &num);
            printf("\n");
            insert(&s,num);
            break;
        case 2:
            printf("Returning %d\n", delete(&s));
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("Somethings not right\n");
        }
    }
    return 0;
}