#include <stdio.h>

char strA[1010], strB[1010];
int d[1010][1010];

int max(int a, int b) { return a > b ? a : b; }

int dp(int n, int m)
{
    if (!n || !m) return 0;
    if (-1 != d[n][m]) return d[n][m];

    if (strA[n] == strB[m]) d[n][m] = dp(n - 1, m - 1) + 1;
    else d[n][m] = max(dp(n - 1, m), dp(n, m - 1));

    return d[n][m];
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = -1;

    scanf("%s%s", strA + 1, strB + 1);

    printf("%d", dp(n, m));

    return 0;
}