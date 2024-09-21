#include <stdio.h>

int n, f;
int cake[10000];

double eps = 1e-6, PI = 3.14159265358979323846;

int check(double len)
{   
    if (len < eps) return 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += cake[i] / len;
    return cnt >= f;
}

double binarySearch(double l, double r)
{
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}


int main()
{
    scanf("%d%d", &n, &f);
    f++;

    int maxCake = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cake[i]);
        cake[i] *= cake[i];
        if (cake[i] > maxCake) maxCake = cake[i];
    }

    double ans = binarySearch(0, maxCake);
    printf("%.3lf\n", ans * PI);

    return 0;
}