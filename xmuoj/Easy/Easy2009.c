#include <stdio.h>
#include <math.h>

int main()
{
    double n, m;
    while (scanf("%lf%lf", &n, &m)!= EOF)
    {
        double sum = n;
        while (--m) n = sqrt(n), sum += n;
        printf("%.2lf\n", sum);
    }

    return 0;
}
