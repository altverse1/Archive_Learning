// Bubble Sort
// Input: array A[0...n-1] and n
// Output: Sorted array in ascending order

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXn 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Swapping %d & %d \n",*a,*b);
}

void arrprint(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void bubble(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}

int main()
{
    int n, a[MAXn];
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    printf("Enter the numbers to sort: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble(a, n);
    printf("Post Sort: \n");
    arrprint(a,n);
    return 0;
}