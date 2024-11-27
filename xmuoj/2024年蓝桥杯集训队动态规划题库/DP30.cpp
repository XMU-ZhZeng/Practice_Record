#include <iostream>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int values[n];
    for (int i = 0; i < n; i++) cin >> values[i];
  
    long long dp[m + 1] = { 0 };
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = values[i]; j <= m; j++)
            dp[j] += dp[j - values[i]];
  
    cout << dp[m];
    
    return 0;
}