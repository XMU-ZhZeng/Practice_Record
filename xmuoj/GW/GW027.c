#include <stdio.h>

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);

    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        int n = i;
        while (n)
        {
            if (n % 10 == 2) cnt++;
            n /= 10;
        }
    }

    printf("%d", cnt);

    return 0;
}