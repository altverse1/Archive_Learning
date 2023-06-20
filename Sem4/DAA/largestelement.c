#include <stdio.h>
#include <stdlib.h>


int getlargest(int *d,int n)
{
    int largest;
    largest = d[0];
    for(int i = 1; i<n; i++)
        if(d[i]>largest)
            largest = d[i];
    return largest;
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
    printf("The largest element is %d",getlargest(arr,n));
    return 0;
}