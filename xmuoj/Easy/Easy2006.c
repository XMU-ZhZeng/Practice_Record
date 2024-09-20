#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n)!= EOF)
    {
        int product = 1, x;
        while (n--)
        {
            scanf("%d", &x);
            if (x % 2) product *= x;
        }
        printf("%d\n", product);
    }

    return 0;
}