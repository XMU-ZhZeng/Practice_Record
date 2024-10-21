#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int flag = 0;
char _operator[6] = {'+', '-', '_', '*', '/', '\\'};

double calculator(double e1, double e2, char _operator)
{
    switch (_operator)
    {
    case '+': return e1 + e2;
    case '-': return e1 - e2;
    case '_': return e2 - e1;
    case '*': return e1 * e2;
    case '/': return e1 / e2;
    case '\\': return e2 / e1;
    }
}

void func(vector<double> v, int n)
{
    if (flag) return;
    if (1 == n)
    {
        double tmp = fabs(v[0]) - 24.0;
        if (tmp > -1e-5 && tmp <= 1e-5) flag = 1;
        return;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < 6; k++)
            {
                vector<double> nv(v);
                nv.push_back(calculator(v[i], v[j], _operator[k]));
                nv.erase(nv.begin() + j);
                nv.erase(nv.begin() + i);
                func(nv, n - 1);
            }
}

int main()
{
    double arr[4];
    while (scanf("%lf%lf%lf%lf", arr, arr + 1 , arr + 2, arr + 3) != EOF
            && (arr[0] || arr[1] || arr[2] || arr[3]))
    {
        vector<double> v(arr, arr + 4);

        flag = 0;
        func(v, 4);

        if (flag) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}