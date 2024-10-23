#include <stdio.h>

int d[100010];

int binarySearch(int *base, int size, int num)
{
    int l = 0, r = size - 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (base[mid] < num) l = mid;
        else r = mid;
    }

    if (base[l] >= num) return l;
    return r;
}

int main()
{
    int n; scanf("%d", &n);

    int len = 1;
    scanf("%d", d);

    while (--n)
    {
        scanf("%d", &d[len]);
        if (d[len] > d[len - 1]) len++;
        else
        {
            d[binarySearch(d, len, d[len])] = d[len];
        }
    }

    printf("%d", len);

    return 0;
}