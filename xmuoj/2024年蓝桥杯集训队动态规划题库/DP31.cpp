#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int values[105];
long long dp[25010] = { 0 };

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> values[i];
        sort(values, values + n);

        memset(dp, 0, (values[n - 1] + 1) * sizeof(long long)); 
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = values[i]; j <= values[n - 1]; j++)
                dp[j] += dp[j - values[i]];
      
        int cnt = n;
        for (int i = 0; i < n; i++) if (dp[values[i]] > 1) cnt--;
        
        cout << cnt << endl;
    }
    
    return 0;
}