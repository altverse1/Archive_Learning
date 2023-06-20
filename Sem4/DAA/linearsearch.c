// Algorithm: Linear Search
// Input: Array and element to search
// Output: Returns index of position if found else returns -1

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int linearsearc(int *d, int search)
{
    for (int i = 0; i < MAX; i++)
        if (d[i] == search)
            return i;
    return -1; // if not found
}

int main()
{
    int pos, n, search, arr[MAX];
    printf("\nSize of array: ");
    scanf("%d", &n);
    printf("\nEnter the list of integers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter element to search: ");
    scanf("%d", &search);
    pos = linearsearc(arr, search);
    if (pos != -1)
        printf("\nFound at %d\n", pos);
    else
        printf("\nNot found\n");

    return 0;
}