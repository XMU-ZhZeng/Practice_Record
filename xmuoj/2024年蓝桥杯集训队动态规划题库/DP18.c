#include <stdio.h>

int dp[52][52][52][52] = { 0 };
int chessboard[52][52] = { 0 };

int max(int a, int b) { return a > b ? a : b; }
 
int main()
{
    int m, n; scanf("%d%d", &m, &n);

    int count = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &chessboard[i][j]);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= i + j - 1 && k < i; k++)
            {
                if (i + j - k > n) continue;

                dp[i][j][k][i + j - k] = max(max(dp[i - 1][j][k - 1][i + j - k], dp[i - 1][j][k][i + j - k - 1]),
                                             max(dp[i][j - 1][k - 1][i + j - k], dp[i][j - 1][k][i + j - k - 1]));
                dp[i][j][k][i + j - k] += chessboard[i][j] + chessboard[k][i + j - k];
            }

    dp[m][n][m][n] = dp[m][n - 1][m - 1][n];
    printf("%d", dp[m][n][m][n]);

    return 0;
}