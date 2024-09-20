#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> a[i][j];

    for (int i = 1; i < n; i++)
    {
        a[i][0] += a[i - 1][0];
        for (int j = 1; j < i; j++)
            a[i][j] += (a[i - 1][j] > a[i - 1][j - 1] ? a[i - 1][j] : a[i - 1][j - 1]); // 状态转移方程(DP)
        a[i][i] += a[i - 1][i - 1];
    }

    int max = 0;
    for (int i = 0; i < n; i++)
        if (a[n - 1][i] > max)
            max = a[n - 1][i];
    cout << max;

    return 0;
}