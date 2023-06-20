//Compute GCD(m,n) by consiqutive Integer checking
//Input: Two non-negative, not both zero integers m and n
//Output: Greatest common divisor of m and n

#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{   
    int min;
    if(m>n)
        min = n;
    else
        min = m;
        
    while(min!=0)
    {
        if(m%min == 0) 
            if(n%min == 0)
                return min;
            else
                min--;
        else
            min--;
    }
}

int main()
{
    printf("GCD of 36 and 8 is %d",gcd(36,8));
    return 0;
}