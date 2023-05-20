//CIRCULAR Queue Using STRUCTURE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

typedef struct QUEUE
{
    int first;
    int data[MAX];
    int last;
}queue;

bool isfull(queue *q)
{
    if((q->first==q->last+1)||(q->first==0 &&q->last==MAX-1))
        return true;
    return false;
}

bool isempty(queue *q)
{
    if(q->first==-1)
        return true;
    return false;
}

void insert(queue*q, int a)
{
    if(isfull(q))
    {
        printf("Nothing more can go in\n");
    }
    else
    {
        if(isempty(q))
            q->first++;
        q->last=(q->last+1)%MAX;
        q->data[q->last] = a;
    }
}

int delete(queue*q)
{
    if(isempty(q))
    {
        printf("Nothing is there to delete\n");
    }
    if(q->last==q->first)
    {
        int temp = q->data[q->first];
        q->last=q->first=-1;
        return temp;
    }   
    else
    {
        int temp = q->data[q->first];
        q->first=(q->first+1)%MAX;
        return temp;
    }
}

void display(queue*q)
{
    int i;
    if(isempty(q))
        printf("Queue Empty\n");
    else{
        printf("|DISPLAY: ");
        for(i = q->first; i!=q->last; i = (i+1)%MAX)
            printf("%d ", q->data[i]);
        printf("%d",q->data[i]);
        printf("|\n");
}
}
int main()
{
    queue s;
    s.first = -1;
    s.last = -1;
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