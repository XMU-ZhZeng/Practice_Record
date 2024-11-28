#include <iostream>

using namespace std;

#define PII pair<int, int>

int N, V;
int vw[1010][2];
int f[1010][1010], cnt[1010][1010];
bool visited[1010][1010] = { 0 };

PII DP(int n, int v)
{
    if (n == 1) return v >= vw[1][0] ? PII(vw[1][1], 1) : PII(0, 1);
    if (visited[n][v]) return {f[n][v], cnt[n][v]};
    
    visited[n][v] = true;
  
    if (v < vw[n][0])
    {
        f[n][v] = DP(n - 1, v).first;
        cnt[n][v] = DP(n - 1, v).second;
        return DP(n - 1, v);
    }
  
    if (DP(n - 1, v).first == DP(n - 1, v - vw[n][0]).first + vw[n][1])
    {
        f[n][v] = DP(n - 1, v).first;
        cnt[n][v] = DP(n - 1, v).second + DP(n - 1, v - vw[n][0]).second;
    }
    else if (DP(n - 1, v).first > DP(n - 1, v - vw[n][0]).first + vw[n][1])
    {
        f[n][v] = DP(n - 1, v).first;
        cnt[n][v] = DP(n - 1, v).second;
    }
    else
    {
        f[n][v] = DP(n - 1, v - vw[n][0]).first + vw[n][1];
        cnt[n][v] = DP(n - 1, v - vw[n][0]).second;
    }
  
    return {f[n][v], cnt[n][v]};
}

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++) cin >> vw[i][0] >> vw[i][1];
    
    cout << DP(N, V).second;

    return 0;
}