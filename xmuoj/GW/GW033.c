#include <stdio.h>

int origin[100][100], target[100][100];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &origin[i][j]);

    for (int i = 0; i < n; i++) target[i][0] = origin[i][0], target[i][m - 1] = origin[i][m - 1];
    for (int i = 0; i < m; i++) target[0][i] = origin[0][i], target[n - 1][i] = origin[n - 1][i];



    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
            target[i][j] = (origin[i][j] + origin[i - 1][j] + origin[i + 1][j] + origin[i][j - 1] + origin[i][j + 1]) / 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j) printf(" ");
            printf("%d", target[i][j]);
        }
        if (i!= n - 1) printf("\n");
    }

    return 0;
}