//Print n fibonacci numbers
//Input n
//Output fibonacci printed

#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib(n-1) + fib(n-2));
}


int main()
{
    int n;
    printf("Enter the number of fibonacci to return: \n");
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        printf("%d ",fib(i));
    }
    return 0;
}