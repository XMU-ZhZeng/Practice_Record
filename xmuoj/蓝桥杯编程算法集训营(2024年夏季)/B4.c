#include <stdio.h>

int arr[1000000];
int queue[1000000], h = 0, t = -1;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // 窗口最小值
    for (int i = 0; i < n; i++)
    {
        if (queue[h] <= i - k) h++;
        while (h <= t && arr[queue[t]] >= arr[i]) t--;
        queue[++t] = i;
        if (i >= k - 1) printf("%d ", arr[queue[h]]);
    }
    printf("\n");
    
    // 窗口最大值
    h = 0, t = -1;
    for (int i = 0; i < n; i++)
    {
        if (queue[h] <= i - k) h++;
        while (h <= t && arr[queue[t]] <= arr[i]) t--;
        queue[++t] = i;
        if (i >= k - 1) printf("%d ", arr[queue[h]]);
    }
    
    return 0;
}