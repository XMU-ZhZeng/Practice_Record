#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[105][105] = { 0 };
vector<pair<int, int>> necklace;

int DP(int l, int r)
{
    if (l >= r) return 0;
 
    if (dp[l][r]) return dp[l][r];
    
    for (int i = l; i <= r - 1; i++)
    {
        int tmp = necklace[l].first * necklace[i].second * necklace[r].second;
        if (necklace[l].first == necklace[r].second) tmp = max(tmp, necklace[r].first * necklace[r].second * necklace[l].second);
        dp[l][r] = max(dp[l][r], DP(l, i) + DP(i + 1, r) + tmp);
    }

    return dp[l][r];
}

int main()
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < n - 1; i++) necklace.push_back({v[i], v[i + 1]});
    necklace.push_back({v[n - 1], v[0]}); 

    int maxE = 0;
    for (int i = 0; i < n; i++)
    {
        memset(dp, 0, 105 * 105 * sizeof(int));

        maxE = max(maxE, DP(0, n - 1));

        necklace.push_back(*(necklace.begin()));
        necklace.erase(necklace.begin());
    }

    cout << maxE;

    return 0;
}