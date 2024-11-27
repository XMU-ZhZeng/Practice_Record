#include <iostream>

using namespace std;

const int N = 105, M = 10010;
int nums[N];
int dp[N][M] = { 0 };
bool visited[N][M] = { 0 };

int DP(int idx, int total)
{
    if (total < 0) return 0;
    if (idx == 1) return (total == nums[1]) || (total == 0);
    if (visited[idx][total]) return dp[idx][total];
    visited[idx][total] = true;
    
    return dp[idx][total] = DP(idx - 1, total) + DP(idx - 1, total - nums[idx]);
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> nums[i];
  
    cout << DP(n, m);
    
    return 0;
}