#include <stdio.h>

int main()
{
    int a, n;
    scanf("%d%d", &a, &n);

    int end = 1;
    for (int i = 1; i <= n; i++) end *= a;

    printf("%d", end);

    return 0;
}