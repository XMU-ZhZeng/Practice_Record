#include <stdio.h>

int binarySearch(int *base, int size, int num, int order)
{
    int l = 0, r = size - 1;

    while (r - l > 1)
    {
        int mid = (r + l) / 2;

        if ((!order && base[mid] > num) || (order && base[mid] < num)) l = mid;
        else r = mid;
    }

    if ((!order && base[l] <= num) || (order && base[l] >= num)) return l;
    return r;
}

int main()
{
    int k; scanf("%d", &k);

    int height[105], dpUp[105], dpDown[105];

    while (k--)
    {
        int n; scanf("%d", &n);

        int lenUp = 1, lenDown = 1;
        scanf("%d", dpDown);
        dpUp[0] = dpDown[0];
        while (--n)
        {
            scanf("%d", &dpDown[lenDown]);
            dpUp[lenUp] = dpDown[lenDown];

            if (dpDown[lenDown] < dpDown[lenDown - 1]) lenDown++;
            else dpDown[binarySearch(dpDown, lenDown, dpDown[lenDown], 0)] = dpDown[lenDown];

            if (dpUp[lenUp] > dpUp[lenUp - 1]) lenUp++;
            else dpUp[binarySearch(dpUp, lenUp, dpUp[lenUp], 1)] = dpUp[lenUp];
        }

        printf("%d\n", (lenDown > lenUp ? lenDown : lenUp));
    }

    return 0;
}