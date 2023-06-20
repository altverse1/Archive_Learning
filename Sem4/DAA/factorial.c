#include <stdio.h>
#include <stdlib.h>

int getfact(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    return(n*getfact(n-1));
}

int main()
{
    int n;
    printf("Enter the element to get factorial of: ");
    scanf("%d", &n);
    printf("\nFactroial is: %d ",getfact(n));
    return 0;
}