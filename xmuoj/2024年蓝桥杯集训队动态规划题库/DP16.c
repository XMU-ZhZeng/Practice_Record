#include <stdio.h>

int dp[105][105];

int main()
{
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &dp[i][j]);
            
            if (1 != i && 1 == j) dp[i][j] += dp[i - 1][j];
            else if (1 == i && 1 != j) dp[i][j] += dp[i][j - 1];
            else dp[i][j] += (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    
    printf("%d\n", dp[n][n]);
    
    return 0;
}