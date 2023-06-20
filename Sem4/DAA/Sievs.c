//Implements the sieve of Eratoshtenes
//Input: A positive integer n>1
//Output: Aray L of all prime numbers less than or equal to n
// IF ERR: undefined reference to 'sqrt' then:
    // compile using: gcc Sievs.c -o sievs -lm
    // run: ./sievs

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gen_prime(int num)
{
    int a[(num-2)];

    for(int i = 2; i<=num; i++)
    {
        a[i-2] = i;
    }
    for(int i = 2; i<=sqrt(num);i++)
    {
        for(int j = 0; j<=num; j++)
        {
            if(a[j]==0)
                continue;
            if(a[j]==i)
                continue;
            if(a[j]%i==0)
               a[j] = 0;
        }
    }
    for(int i = 0; i<num; i++)
    {
        if(a[i]!=0)
            printf("%d ",a[i]);
    }
}



int main()
{
    gen_prime(25);
    return 0;
}
