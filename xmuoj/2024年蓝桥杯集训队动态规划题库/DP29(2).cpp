#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int dp[n + 1] = { 0 };
    dp[0] = 1;
    int d[] = { 10, 20, 50, 100 };
    for (int i = 0; i < 4; i++)
        for (int j = d[i]; j <= n; j += 10)
            dp[j] += dp[j - d[i]];
    cout << dp[n];
    return 0;
}