#include <stdio.h>

char load[10001] = { 0 };

int main()
{
    int l, m;
    scanf("%d%d", &l, &m);

    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        for (int i = x; i <= y; i++) load[i] = 1;
    }

    int cnt = 0;
    for (int i = 0; i <= l; i++) cnt += load[i];

    printf("%d", l + 1 - cnt);

    return 0;
}