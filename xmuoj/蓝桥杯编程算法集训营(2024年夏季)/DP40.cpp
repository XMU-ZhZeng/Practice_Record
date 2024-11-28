#include <iostream>

using namespace std;

int N, V;
int vw[1010][2];
int f[1010][1010];
bool visited[1010][1010] = { 0 }, choosed[1010][1010] = { 0 };

int DP(int n, int v)
{
    if (visited[n][v]) return f[n][v];
    visited[n][v] = true;

    if (n == N)
    {
        if (v >= vw[n][0])
        {
            f[n][v] = vw[n][1];
            choosed[n][v] = true;
        }
        else
        {
            f[n][v] = 0;
            choosed[n][v] = false;
        }
        return f[n][v];
    }
  
    if (v < vw[n][0])
    {
        choosed[n][v] = false;
        f[n][v] = DP(n + 1, v);
        return f[n][v];
    }
  
    if (DP(n + 1, v - vw[n][0]) + vw[n][1] >= DP(n + 1, v))
    {
        choosed[n][v] = true;
        f[n][v] = DP(n + 1, v - vw[n][0]) + vw[n][1];
    }
    else
    {
        choosed[n][v] = false;
        f[n][v] = DP(n + 1, v);
    }
  
    return f[n][v];
}

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++) cin >> vw[i][0] >> vw[i][1];

    DP(1, V);
  
    int i = 1, j = V;
    while (i <= N)
    {
        if (choosed[i][j]) cout << i << " ";
        j -= (choosed[i][j] ? vw[i][0] : 0);
        i++;
    }
  
    return 0;
}