#include <stdio.h>
#include <stdlib.h>
int middleSchool(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int i = 2, gcd = 1;

    while (a >= i && b >= i)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                gcd = gcd * i;
                b = b / i;
            }
            a = a / i;
        }
        else
            i++;
    }
    return gcd;
}

int main()
{
    int a, b, gcd;
    printf("Enter the first number:  ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    gcd = middleSchool(a, b);
    printf("\n3-GCD using mid school method:    %d", gcd);

    return 0;
}