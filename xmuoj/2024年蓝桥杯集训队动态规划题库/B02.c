#include <stdio.h>

int vw[1010][3];
int dp[1010][2010] = { 0 };

int main()
{
    int N, V; scanf("%d%d", &N, &V);

    for (int i = 1; i <= N; i++) scanf("%d%d%d", &vw[i][0], &vw[i][1], &vw[i][2]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= V; j++)
        {
            int k = 0;
            while (k * vw[i][0] <= j && k <= vw[i][2])
            {
                dp[i][j] = dp[i][j] > dp[i - 1][j - k * vw[i][0]] + k * vw[i][1]? dp[i][j] : dp[i - 1][j - k * vw[i][0]] + k * vw[i][1];
                k++;
            }
        }
    printf("%d", dp[N][V]);

    return 0;
}