#include <stdio.h>

int main()
{
    int N;
    while (scanf("%d", &N) != EOF && N != 0)
    {
        int p = 0, z = 0, n = 0;
        double x;
        while (N--)
        {
            scanf("%lf", &x);
            if (x > 0) p++;
            else if (x < 0) n++;
            else z++;
        }
        printf("%d %d %d\n", n, z, p);
    }
}