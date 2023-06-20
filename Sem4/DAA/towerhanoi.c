//Tower Of Hanoi
//Input, number of disks and rods
//Output, god knows

#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char mid, char destiny)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", source, mid);
        return;
    }
    towerOfHanoi(n-1, source, destiny, mid);
    printf("\n Move disk %d from rod %c to rod %c", n, source, mid);
    towerOfHanoi(n-1, destiny, mid, source);
}
 
int main()
{
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'B', 'C');  // A, B and C are names of rods
    return 0;
}