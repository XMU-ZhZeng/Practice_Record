#include <stdio.h>

int matrix[6][6];

int main()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &matrix[i][j]);

    
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int flag = 0;
            for (int k = 1; k <= 5; k++)
                if (matrix[i][j] < matrix[i][k])
                {
                    flag = 1;
                    break;
                }
            for (int k = 1; k <= 5; k++)
                if (matrix[i][j] > matrix[k][j])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
            {
                printf("%d %d %d", i, j, matrix[i][j]);
                return 0;
            }
        }
    }

    printf("not found");

    return 0;
}