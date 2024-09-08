#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int *arr = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        int l,r;
        scanf("%d %d", &l, &r);
        int sum = 0;
        for (int j = l - 1; j <= r - 1; j++)
            sum += arr[j];
        printf("%d\n", sum);
    }
    free(arr);
    return 0;
}