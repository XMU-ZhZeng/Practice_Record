#include <stdio.h>

int n, m;
int vp[30][2];
int dp[30][30010];
char visited[30][30010];

int max(int a, int b) { return a > b ? a : b; }

int DP(int idx, int money)
{
    if (idx == 1) return (money >= vp[1][0] ? vp[1][0] * vp[1][1] : 0);
    if (visited[idx][money]) return dp[idx][money];
  
    visited[idx][money] = 1;
    
    if (money < vp[idx][0]) return dp[idx][money] = DP(idx - 1, money);
    return dp[idx][money] = max(DP(idx - 1, money), DP(idx - 1, money - vp[idx][0]) + vp[idx][0] * vp[idx][1]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &vp[i][0], &vp[i][1]);
  
    printf("%d", DP(m, n));
    
    return 0;
}