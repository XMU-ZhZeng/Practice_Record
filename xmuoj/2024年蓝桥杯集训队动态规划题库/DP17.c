#include <stdio.h>

int dp[12][12][12][12] = { 0 };
int chessboard[12][12] = { 0 };

int max(int a, int b) { return a > b ? a : b; }
 
int main()
{
    int n; scanf("%d", &n);

    int x, y, z;
    while (scanf("%d%d%d", &x, &y, &z) != EOF && x && y && z) chessboard[x][y] = z;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; (k <= i + j - 1) && (k <= n); k++)
            {
                if (i + j - k > n) continue;
                dp[i][j][k][i + j - k] = max(max(dp[i - 1][j][k - 1][i + j - k], dp[i - 1][j][k][i + j - k - 1]),
                                             max(dp[i][j - 1][k - 1][i + j - k], dp[i][j - 1][k][i + j - k - 1]));
                dp[i][j][k][i + j - k] += chessboard[i][j] + chessboard[k][i + j - k];
                if (i == k) dp[i][j][k][i + j - k] -= chessboard[i][j];
            }

    printf("%d", dp[n][n][n][n]);

    return 0;
}