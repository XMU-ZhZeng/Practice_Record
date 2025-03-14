#include <stdio.h>

int n, m[305];
int dp[305][305];
int mSum[305];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &m[i]);

    mSum[0] = m[0];
    for (int i = 1; i < n; i++) mSum[i] = mSum[i - 1] + m[i];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        for (int j = i + 1; j < n; j++)
            dp[i][j] = 0x7FFFFFFF;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int sum = mSum[i + len - 1] - mSum[i - 1];
            for (int j = i; j < i + len - 1; j++)
            {
                int cost = dp[i][j] + dp[j + 1][i + len - 1] + sum;
                if (cost < dp[i][i + len - 1]) dp[i][i + len - 1] = cost;
            }
        }
    }

    printf("%d", dp[0][n - 1]);

    return 0;
}
