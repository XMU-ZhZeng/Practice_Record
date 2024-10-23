#include <stdio.h>

int nums[1010], dp[1010];

int main()
{
    int n; scanf("%d", &n);

    int max = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        dp[i] = 1;
        for (int j = 0; j <= i - 1; j++)
            if (nums[i] > nums[j])
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
        if (dp[i] > max) max = dp[i];
    }

    printf("%d", max);

    return 0;
}