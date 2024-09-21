#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iomanip>

double f(double x) { return x * x * x - 5 * x * x + 10 * x - 80; }

double dichotomy(double l, double r)
{
    while (r - l > 1e-11)
    {
        double mid = (l + r) / 2;
        if (f(mid) > 0) r = mid;
        else l = mid;
    }
    return l;
}

int main()
{
    cout << fixed << setprecision(9) << dichotomy(0, 10); 

    return 0;
}