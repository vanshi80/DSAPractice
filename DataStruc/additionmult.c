#include <stdio.h>

int main()
{
    int r1, c1, r2, c2;

    // Input sizes
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check for valid addition
    if (r1 != r2 || c1 != c2)
    {
        printf("\nMatrix addition not possible (dimensions must be same).\n");
    }

    // Check for valid multiplication
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible (columns of first must equal rows of second).\n");
        return 0;
    }

    // Declare matrices
    int a[r1][c1], b[r2][c2], sum[r1][c1], product[r1][c2];

    // Input first matrix
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }

    // Input second matrix
    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }

    // Matrix Addition (only if possible)
    if (r1 == r2 && c1 == c2)
    {
        printf("\nMatrix Addition Result:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                sum[i][j] = a[i][j] + b[i][j];
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }
    }

    // Matrix Multiplication
    printf("\nMatrix Multiplication Result:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
