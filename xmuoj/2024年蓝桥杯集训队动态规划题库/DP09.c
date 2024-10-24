#include <stdio.h>

int vw[105][105][2];
int dp[105][105] = { 0 };

int main()
{
    int N, V; scanf("%d%d", &N, &V);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &vw[i][0][0]);
        for (int j = 1; j <= vw[i][0][0]; j++)
            scanf("%d%d", &vw[i][j][0], &vw[i][j][1]);
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int k = 1;
            while (k <= vw[i][0][0])
            {
                int b = 0;
                if (j >= vw[i][k][0]) b = dp[i - 1][j - vw[i][k][0]] + vw[i][k][1];
                dp[i][j] = dp[i][j] > b ? dp[i][j] : b;
                k++;
            }
        }

    printf("%d", dp[N][V]);

    return 0;
}