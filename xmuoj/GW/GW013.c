#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double d = b * b - 4 * a * c;
    if (d >= 0)
    {
        printf("x1=");
        if (fabs((-b + sqrt(d)) / (2 * a)) < 1e-9)  printf("%.5lf", fabs((-b + sqrt(d)) / (2 * a)));
        else printf("%d", (-b + sqrt(d)) / (2 * a));
        printf(";x2=");
        if (fabs((-b - sqrt(d)) / (2 * a)) < 1e-9)  printf("%.5lf", fabs((-b + sqrt(d)) / (2 * a)));
        else printf("%d", (-b - sqrt(d)) / (2 * a));
    }
    else
    {   
        double r = -b / (2 * a), v = sqrt(-d) / (2 * a);
        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi", (fabs(r) < 1e-9 ? fabs(r) : r), fabs(v), (fabs(r) < 1e-9 ? fabs(r) : r), fabs(v));
    }

    return 0;
}