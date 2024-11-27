#include <iostream>
#include <algorithm>

using namespace std;

int v, n;
int vs[35];
int dp[35][20010] = { 0 };
bool visited[35][20010] = { 0 };

int DP(int idx, int volume)
{
    if (idx == 1) return (volume >= vs[1] ? volume - vs[1] : volume);
    if (visited[idx][volume]) return dp[idx][volume];
  
    visited[idx][volume] = true;
    if (volume < vs[idx]) return dp[idx][volume] = DP(idx - 1, volume);
    return dp[idx][volume] = min(DP(idx - 1, volume - vs[idx]), DP(idx - 1, volume));
}

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= n; i++) cin >> vs[i];
  
    cout << DP(n, v);
    
    return 0;
}