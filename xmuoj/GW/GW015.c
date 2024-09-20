#include <stdio.h>

int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    printf("%d", n - (y % x ? y / x + 1 : y / x));

    return 0;
}