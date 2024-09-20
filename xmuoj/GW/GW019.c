#include <stdio.h>

int main()
{
    int n, gold = 0, silver = 0, bronze = 0, sum = 0;
    scanf("%d", &n);

    int x, y, z;
    while (n--)
    {
        scanf("%d%d%d", &x, &y, &z);
        gold += x, silver += y, bronze += z;
    }

    sum = gold + silver + bronze;
    printf("%d %d %d %d", gold, silver, bronze, sum);

    return 0;
}