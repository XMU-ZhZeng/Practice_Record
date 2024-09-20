#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    if (b > a)
    {
        int t = a;
        a = b;
        b = t;
    }

    while (a % b)
    {
        int t = a % b;
        a = b;
        b = t;
    }

    printf("%d", b);

    return 0;
}