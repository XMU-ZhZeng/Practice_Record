#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int (*arr)[m] = (int (*)[m])malloc(sizeof(int[m]) * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i == 0 && j != 0)
                arr[i][j] += arr[i][j - 1];
            else if (j == 0 && i!= 0)
                arr[i][j] += arr[i - 1][j];
            else if (i!= 0 && j!= 0)
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
        
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // printf("%d\n", arr[x2 - 1][y2 - 1] - arr[x1 - 2][y2 - 1] - arr[x2 - 1][y1 - 2] + arr[x1 - 2][y1 - 2]);
        if (x1 == 1 && y1 == 1)
            printf("%d\n", arr[x2 - 1][y2 - 1]);
        else if (x1 == 1)
            printf("%d\n", arr[x2 - 1][y2 - 1] - arr[x2 - 1][y1 - 2]);
        else if (y1 == 1)
            printf("%d\n", arr[x2 - 1][y2 - 1] - arr[x1 - 2][y2 - 1]);
        else
            printf("%d\n", arr[x2 - 1][y2 - 1] - arr[x1 - 2][y2 - 1] - arr[x2 - 1][y1 - 2] + arr[x1 - 2][y1 - 2]);
    }
    free(arr);
    return 0;
}