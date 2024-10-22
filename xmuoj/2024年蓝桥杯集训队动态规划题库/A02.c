#include <stdio.h>

int vw[1010][2];
int dp[1010][1010] = { 0 };

int main()
{
    int N, V; scanf("%d%d", &N, &V);

    for (int i = 1; i <= N; i++) scanf("%d%d", &vw[i][0], &vw[i][1]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= V; j++)
            if (j >= vw[i][0])
                dp[i][j] = dp[i - 1][j - vw[i][0]] + vw[i][1] > dp[i - 1][j] ? dp[i - 1][j - vw[i][0]] + vw[i][1] : dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
    
    printf("%d", dp[N][V]);

    return 0;
}