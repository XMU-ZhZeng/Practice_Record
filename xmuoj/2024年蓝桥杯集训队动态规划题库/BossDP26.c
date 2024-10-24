#include <stdio.h>

int a[3010], b[3010];
int dp[3010][3010] = { 0 };

int max(int e1, int e2) { return e1 > e2 ? e1 : e2; }

int main()
{
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (a[i] == b[j])
            {
                int maxLen = 1;
                for (int k = 1; k < j; k++)
                    if (b[j] > b[k])
                        maxLen = max(maxLen, dp[i][k] + 1);
                dp[i][j] =max(maxLen, dp[i][j]);
            }
        }

    int maxLen = 0;
    for (int i = 1; i <= n; i++) maxLen = max(maxLen, dp[n][i]);
    printf("%d", maxLen);

    return 0;
}