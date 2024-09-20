#include <stdio.h>

int main()
{
    int n; 
    scanf("%d", &n);

    double x0, y0, z0;
    scanf("%lf%lf", &x0, &y0);
    z0 = y0 / x0;

    double x, y;
    while (--n)
    {
        scanf("%lf%lf", &x, &y);
        if (y / x > z0 + 0.05) printf("better\n");
        else if (y / x < z0 - 0.05) printf("worse\n");
        else printf("same\n");
    }

    return 0;
}