#include <stdio.h>

int main()
{
    int n, arr[100];
    while (scanf("%d", &n)!= EOF)
    {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        
        int max = arr[0], min = arr[0], sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
            sum += arr[i];
        }

        printf("%.2f\n", (float)(sum - max - min) / (n - 2));
    }

    return 0;
}