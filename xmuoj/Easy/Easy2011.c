#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &x);
        double sum = 0;
        for (int i = 1; i <= x; i++) sum += 1.0 / i * (i % 2 ? 1 : -1);
        printf("%.2lf\n", sum);
    }

    return 0;
}