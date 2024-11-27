#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << 11;
long long dp[N][M];
vector<int> last_state[M];
bool state_check[M];

int main()
{
    int n, m;
    
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (i >> j & 1)
                {
                    if (cnt & 1) break;
                }
                else cnt++;
            state_check[i] = !(cnt & 1);
        }
      
        for (int i = 0; i < 1 << n; i++)
        {
            last_state[i].clear();
            for (int j = 0; j < 1 << n; j++)
                if (!(i & j) && state_check[i | j])
                    last_state[i].push_back(j);
        }
      
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++)
            for (int j = 0; j < 1 << n; j++)
                for (auto it : last_state[j])
                    dp[i][j] += dp[i - 1][it];
      
        for (int j = 0; j < 1 << n; j++)
            for (auto it : last_state[j])
                dp[m][j] += dp[m - 1][it];
      
        cout << dp[m][0] << endl;
    }
    
    return 0;
}