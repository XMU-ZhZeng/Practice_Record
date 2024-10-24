#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);

    int nums[1010], d[1010];
    int max = 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        d[i] = 1;

        for (int j = 0; j <= i - 1; j++)
            if (nums[i] > nums[j]) d[i] = d[i] > d[j] + 1 ? d[i] : d[j] + 1;
        
        if (d[i] > max) max = d[i];
    }

    printf("%d", max);

    return 0;
}