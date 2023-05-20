// Priority Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX], front = 0, rear = -1;

void insert(int d)
{
    int pos, temp;
    if ((front == 0 && rear == MAX - 1) || front == MAX - 1)
        printf("Queue Full\n");
    else
    {
        rear = rear + 1;
        queue[rear] = d;
    }
    for (int i = front; i < rear; i++)
    {
        pos = i;
        for (int j = i + 1; j < rear + 1; j++)
        {
            if (queue[j] < queue[pos])
            {
                pos = j;
            }
        }
        temp = queue[i];
        queue[i] = queue[pos];
        queue[pos] = temp;
    }
}
int delete()
{
    int temp = -1;
    if ((front == 0 && rear == -1) || (front == rear + 1))
        printf("Empty Queue\n");
    else
    {
        temp = queue[front];
        front = front + 1;
    }
    return temp;
}
void display()
{
    if ((front == 0 && rear == -1) || (front == rear + 1))
        printf("Empty Queue\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}
int main()
{
    int i, c;
    while (1)
    {
        printf("Press 1) Insert     2)Delete     3)Display      4)Exit\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the number to insert\n");
            scanf("%d", &c);
            insert(c);
            break;
        case 2:
            printf("The delete value is %d\n", delete ());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input");
        }
    }
    return 0;
}