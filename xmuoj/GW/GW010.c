#include <stdio.h>

int main()
{
    double a;
    scanf("%lf", &a);
    printf("%.2lf", a * a * a * 3.14 * 4 / 3);
    return 0;
}