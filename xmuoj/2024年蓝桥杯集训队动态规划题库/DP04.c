#include <stdio.h>

int n, rocks[310], dp[310][310] = { 0 };

int DP(int l, int r)
{
    if (l >= r) return 0;
    else if (dp[l][r]) return dp[l][r];

    dp[l][r] = 0x7fffffff;
    int sum = 0;
    for (int i = l; i <= r; i++) sum += rocks[i];
    for (int i = l; i < r; i++)
    {
        int temp = DP(l, i) + DP(i + 1, r) + sum;
        if (temp < dp[l][r]) dp[l][r] = temp;
    }

    return dp[l][r];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &rocks[i]);

    printf("%d", DP(1, n));

    return 0;
}