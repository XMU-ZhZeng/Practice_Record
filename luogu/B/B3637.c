#include <stdio.h>

int arr[5050], dp[5050];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]), dp[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j]) dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;

    int max = 0;
    for (int i = 0; i < n; i++) max = max > dp[i]? max : dp[i];
    printf("%d\n", max);

    return 0;
}