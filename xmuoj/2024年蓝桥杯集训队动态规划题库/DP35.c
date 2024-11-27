#include <stdio.h>

int m, n, k;
int onm[1010][3];
int dp[1010][25][85];
char visited[1010][25][85] = { 0 };

int min(int a, int b) { return (a < b ? a : b); }

int DP(int k, int o, int n)
{
    if (k == 1)
    {
        if (!o && !n) return 0;
        if (o <= onm[1][0] && n <= onm[1][1]) return onm[1][2];
        return 0x3f3f3f3f;
    }
    if (visited[k][o][n]) return dp[k][o][n];
  
    visited[k][o][n] = 1;
    
    return dp[k][o][n] = min(DP(k - 1, o, n), DP(k - 1, (o - onm[k][0] >= 0 ? o - onm[k][0] : 0), (n - onm[k][1] >= 0 ? n - onm[k][1] : 0)) + onm[k][2]);
}

int main()
{
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d%d%d", &onm[i][0], &onm[i][1], &onm[i][2]);
    
    printf("%d", DP(k, m, n));
    
    return 0;
}
