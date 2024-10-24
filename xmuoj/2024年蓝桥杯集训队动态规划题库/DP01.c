#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    int *sums = (int*)malloc(n * sizeof(int));

    sums[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            scanf("%d", &nums[j]);

            if (j == 0) nums[j] += sums[j];
            else if (j == i - 1) nums[j] += sums[j - 1];
            else nums[j] += (sums[j] > sums[j - 1] ? sums[j] : sums[j - 1]);
        }
        int *tmp = sums;
        sums = nums;
        nums = tmp;
    }
    
    int max = sums[0];
    for (int i = 1; i < n; i++) if (sums[i] > max) max = sums[i];

    printf("%d\n", max);

    free(nums);
    free(sums);

    return 0;
}