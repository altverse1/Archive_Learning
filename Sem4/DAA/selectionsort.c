//Program to sort a array using selection sort
//Input: array A[0...n-1] and n
//Output: Sorted array in ascending order

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAXn 10
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void selecsort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        if (min != i)
        {
            swap(&a[min], &a[i]);
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
    selecsort(a, n);
    printf("Post Sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}