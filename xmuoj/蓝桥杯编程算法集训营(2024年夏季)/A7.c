#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    scanf("%d", &arr[0]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }

    if (n < 3)
    {
        printf("0");
        return 0;
    }

    int count = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        if (arr[i] * 3 != arr[n - 1])
            continue;
        for (int j = i + 1; j <= n - 2; j++)
            if (arr[i] * 2 == arr[j])
                count++;
    }
    printf("%d", count);
    return 0;
}