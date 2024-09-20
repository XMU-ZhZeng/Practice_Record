#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 0)
    {
        printf("-");
        n = -n;
    }

    int flag = 0;
    while (n)
    {
        int digit = n % 10;
        if (digit) flag = 1;
        if (flag) printf("%d", digit);
        n /= 10;
    }

    return 0;
}