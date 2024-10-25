#include <stdio.h>

int binarySearch(int *base, int size, int num)
{
    int l = 0, r = size - 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (base[mid] >= num) r = mid;
        else l = mid;
    }

    if (base[l] >= num) return l;
    return r;
}

int main()
{
    int n; scanf("%d", &n);

    int height[1010];
    for (int i = 0; i < n; i++) scanf("%d", &height[i]);

    int dp[1010];
    int count[1010] = { 0 };
    int len = 1;
    dp[0] = height[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[len - 1] < height[i]) dp[len++] = height[i];
        else dp[binarySearch(dp, len, height[i])] = height[i];

        count[i] += len;
    }

    dp[0] = height[n - 1], len = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[len - 1] < height[i]) dp[len++] = height[i];
        else dp[binarySearch(dp, len, height[i])] = height[i];

        count[i] += len;
    }

    int max = count[0];
    for (int i = 1; i < n; i++) max = (max > count[i] ? max : count[i]);
    printf("%d", n - max + 1);

    return 0;
}