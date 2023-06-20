#include <stdio.h>
#include <stdlib.h>

void read(int x[10][10], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d", &x[i][j]);

}
void display(int x[10][10], int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        printf("\n");
        for(j=0;j<col;j++)
            printf("%d\t", x[i][j]);

    }
}
void multiply(int a[10][10], int b[10][10], int c[10][10], int m, int n, int q)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }

}

int main()
{
    int a[10][10], b[10][10], c[10][10], m, n, p, q, i, j, k;
    printf("Enter the rows and columns of the first matrix\n");
    scanf("%d%d",&m,&n);

    printf("Enter the rows and columns of the second matrix\n");
    scanf("%d%d",&p,&q);

    if(n!=p)
    {
        printf("The two matrices can't be multiplied, please re-enter the order\n ");
        exit(0);
    }

    printf("Enter the elements of the first matrix: ");
    read(a,m,n);


    printf("Enter the elements of the second matrix: ");
    read(b,p,q);

    printf("The entered first matrix is \n");
    display(a,m,n);

    printf("\nThe entered second matrix is \n");
    display(b,p,q);

    multiply(a,b,c,m,n,q);

    printf("\nThe resultant matrix is: \n");
    display(c, m, q);
    return 0;

}

