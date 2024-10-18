#include <stdio.h>

int N, F;
int cakes[10000];

int check(double v)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        count += cakes[i] * cakes[i] / v;
        if (count >= F) break;
    }
    return count - F;
}

double findMax()
{
    double l = 0.0, r = 0.0;
    for (int i = 0; i < N; i++) r += (double)cakes[i] * cakes[i];
    
    while (r - l > 1e-6)
    {
        double mid = (r + l) / 2;
        if (check(mid) >= 0) l = mid;
        else r = mid;
    }
    
    return r;
}

int main()
{
    scanf("%d%d", &N, &F); F++;
    for (int i = 0; i < N; i++) scanf("%d", &cakes[i]);
    printf("%.3lf", findMax() * 3.1415926);
    return 0;
}