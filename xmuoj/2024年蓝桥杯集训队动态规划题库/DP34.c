#include <stdio.h>

int n, v, m;
int vmw[1010][3];
int dp[1010][105][105] = { 0 };
char visited[1010][105][105] = { 0 };

int DP(int n, int v, int m)
{
    if (n == 1) return (v >= vmw[1][0] && m >= vmw[1][1] ? vmw[1][2] : 0);
    if (visited[n][v][m]) return dp[n][v][m];
  
    visited[n][v][m] = 1;
  
    if (v < vmw[n][0] || m < vmw[n][1]) return dp[n][v][m] = DP(n - 1, v, m);
    return dp[n][v][m] = (DP(n - 1, v, m) > DP(n - 1, v - vmw[n][0], m - vmw[n][1]) + vmw[n][2] ? DP(n - 1, v, m) : DP(n - 1, v - vmw[n][0], m - vmw[n][1]) + vmw[n][2]);
}

int main()
{
    scanf("%d%d%d", &n, &v, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &vmw[i][0], &vmw[i][1], &vmw[i][2]);
    
    printf("%d", DP(n, v, m));
  
    return 0;
}