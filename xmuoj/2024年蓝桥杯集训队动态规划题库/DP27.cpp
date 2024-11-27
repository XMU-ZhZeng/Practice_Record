#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define PII pair<int, int>

int n, m, k;
PII arr[105];
PII dp[105][1010][505];
bool visited[105][1010][505] = { 0 };

PII DP(int k, int n, int m)
{
    if (k == 1)
    {
        if (n >= arr[1].first && m >= arr[1].second) return {1, m - arr[1].second};
        return {0, m};
    }
    if (visited[k][n][m]) return dp[k][n][m];
    
    visited[k][n][m] = true;
    
    if (n < arr[k].first || m <= arr[k].second) return dp[k][n][m] = DP(k - 1, n, m);
    if (DP(k - 1, n, m).first == DP(k - 1, n - arr[k].first, m - arr[k].second).first + 1)
    {
        dp[k][n][m].first = DP(k - 1, n, m).first;
        dp[k][n][m].second = max(DP(k - 1, n, m).second, DP(k - 1, n - arr[k].first, m - arr[k].second).second);
    }
    else
    {
        dp[k][n][m].first = max(DP(k - 1, n, m).first, DP(k - 1, n - arr[k].first, m - arr[k].second).first + 1);
        dp[k][n][m].second = (DP(k - 1, n, m).first > DP(k - 1, n - arr[k].first, m - arr[k].second).first + 1 ? 
                             DP(k - 1, n, m).second : DP(k - 1, n - arr[k].first, m - arr[k].second).second);
    }
    return dp[k][n][m];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> arr[i].first >> arr[i].second;
    
    cout <<  DP(k, n, m).first << " " <<  DP(k, n, m).second;  
  
    return 0;
}