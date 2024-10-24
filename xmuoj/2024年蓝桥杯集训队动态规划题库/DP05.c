#include <stdio.h>

int n, m;
char aStr[1010], bStr[1010];
int dp[1010][1010];

int DP(int a, int b)
{

    if (a == 0 || b == 0) return 0;
    if (dp[a][b] != -1) return dp[a][b];

    if (aStr[a] == bStr[b]) dp[a][b] = 1 + DP(a - 1, b - 1);
    else dp[a][b] = DP(a - 1, b) > DP(a, b - 1) ? DP(a - 1, b) : DP(a, b - 1);

    return dp[a][b];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = -1;

    scanf("%s", aStr + 1);
    scanf("%s", bStr + 1);

    printf("%d", DP(n, m));

    return 0;
}