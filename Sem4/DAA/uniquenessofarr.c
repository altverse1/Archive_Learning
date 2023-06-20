#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool isunique(int *arr, int n)
{
    for(int i = 0; i<n;i++)
        for (int j = i+1; j<n; j++)
            if(arr[i]==arr[j])
                return false;
    return true;
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int)); 
    printf("Enter %d elements: ",n);
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);
    if(isunique(arr,n)==true)
        printf("Yes it is");
    else
        printf("No it is not");
    return 0;
}