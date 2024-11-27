#include <iostream>
#include <algorithm>

using namespace std;

int values[1010][3];
int dp[1010][20010] = { 0 };
bool visited[1010][20010] = { 0 };

int DP(int n, int v)
{
    if (!n) return 0;
    if (visited[n][v]) return dp[n][v];
    
    visited[n][v] = true;
  
    for (int i = 0; (v >= i * values[n][0]) && (i <= values[n][2]); i++)
        dp[n][v] = max(dp[n][v], DP(n - 1, v - i * values[n][0]) + i * values[n][1]);
    return dp[n][v];
}


int main()
{
    int n, v; cin >> n >> v;
    for (int i = 1; i <= n; i++) cin >> values[i][0] >>values[i][1] >> values[i][2];
     
    cout << DP(n, v);  
  
    return 0;
}