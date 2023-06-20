//Compute GCD(m,n) by Euclid's algorithm
//Input: Two non-negative, not both zero integers m and n
//Output: Greates common divisor of m and n

#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{   
    int rem;
    while(n!=0)
    {
        rem = m%n;
        m=n;
        n=rem;
    }
    return m;
}

int main()
{
    printf("GCD of 24 and 10 is %d",gcd(36,12));
    return 0;
}
