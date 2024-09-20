#include <stdio.h>

int matrix[100][100];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (j != n - 1) printf("\n");
    }

    return 0;
}