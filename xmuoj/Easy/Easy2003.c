#include <stdio.h>

int main()
{
    double a;
    while (scanf("%lf", &a)!= EOF)
    {
        if (a >= -1e-9 && a <= 1e-9) { printf("0.00\n"); continue; }
        printf("%.2lf\n", a >= 0 ? a : -a);
    }
        
    return 0;
}