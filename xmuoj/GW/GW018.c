#include <stdio.h>

int main()
{
    int n, min = 1000, max = 0;
    scanf("%d", &n);

    int x;
    while (n--)
    {
        scanf("%d", &x);
        if (x > max) max = x;
        if (x < min) min = x;
    }

    printf("%d", max - min);

    return 0;
}