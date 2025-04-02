#include <stdio.h>

int arr[105];
int sums[105];
int minDp[105][105], maxDp[105][105];

int min(int a, int b) { return a < b? a : b; }
int max(int a, int b) { return a > b? a : b; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    sums[0] = arr[0];
    for (int i = 1; i < n; i++) sums[i] = sums[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            minDp[i][j] = 0x3F3F3F3F, maxDp[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        minDp[i][i] = maxDp[i][i] = 0;
        if (i + 1 <= n - 1) minDp[i][i + 1] = maxDp[i][i + 1] = arr[i] + arr[i + 1];
        else minDp[i][i + 1 - n] = maxDp[i][i + 1 - n] = arr[i] + arr[i + 1 - n];
    }

    for (int len = 2; len <= n - 1; len++)
    {
        for (int i = 0; i < n; i++)
        {
            int right = (i + len <= n - 1) ? i + len : i + len - n;
            int sum = (i + len <= n - 1) ? sums[i + len] - sums[i] + arr[i] : sums[n - 1] - sums[i] + arr[i] + sums[right];
            for (int j = i; j < i + len; j++)
            {
                int lRight = (j <= n - 1) ? j : j - n;
                int Rleft = (j + 1 <= n - 1) ? j + 1 : j + 1 - n;
                minDp[i][right] = min(minDp[i][right], minDp[i][lRight] + minDp[Rleft][right] + sum);
                maxDp[i][right] = max(maxDp[i][right], maxDp[i][lRight] + maxDp[Rleft][right] + sum);
            }
        }
    }

    int minCost = minDp[0][n - 1], maxCost = maxDp[0][n - 1];
    for (int i = 1; i < n; i++)
    {
        minCost = min(minCost, minDp[i][i - 1]);
        maxCost = max(maxCost, maxDp[i][i - 1]);
    }

    printf("%d\n%d\n", minCost, maxCost);
    return 0;
}