#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *base, int size, int num)
{
    int l = 0, r = size - 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (base[mid] >= num) r = mid;
        else l = mid;
    }

    if (base[l] >= num) return l;
    return r;
}

int main()
{
    int n; scanf("%d", &n);

    int *d = (int*)malloc(n * sizeof(int));

    int len = 1;
    scanf("%d", d);

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &d[len]);
        if (d[len] > d[len - 1]) len++;
        else d[binarySearch(d, len, d[len])] = d[len];
    }

    printf("%d", len);

    free(d);

    return 0;
}