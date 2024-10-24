#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> H;
vector<vector<int>> tree(6010, vector<int>());
int dp[6010][2] = { 0 };

int DP(int node, int isIn)
{
    if (dp[node][isIn]) return dp[node][isIn];
    if (tree[node].empty())
    {
        if (isIn) return H[node];
        return 0;
    }

    dp[node][isIn] = isIn ? H[node] : 0;
    if (isIn) for (auto it : tree[node]) dp[node][isIn] += DP(it, 0);
    else for (auto it : tree[node]) dp[node][isIn] += max(DP(it, 0), DP(it, 1));

    return dp[node][isIn];
}

int main()
{
    
    int n; cin >> n;

    H.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        H.push_back(tmp);
    }

    int child[n + 1] = { 0 };
    for (int i = 0; i < n - 1; i++)
    {
        int L, K; cin >> L >> K;
        tree[K].push_back(L);
        child[L] = 1;  
    }

    int head;
    for (int i = 1; i <= n; i++)
    {
        if (!child[i])
        {
            head = i;
            break;
        }
    }
 
    int res = max(DP(head, 0), DP(head, 1));
    cout << res;

    return 0;
}