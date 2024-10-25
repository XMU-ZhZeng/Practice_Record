#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);

    int nums[1010], dp[1010];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        dp[i] = nums[i];
        for (int j = 0; j <= i - 1; j++)
            if (nums[i] > nums[j])
                dp[i] = dp[i] > dp[j] + nums[i] ? dp[i] : dp[j] + nums[i];
    }

    int max = dp[0];
    for (int i = 1; i < n - 1; i++) max = (max > dp[i] ? max : dp[i]);
    printf("%d", max);

    return 0;
}