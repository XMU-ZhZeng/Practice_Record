#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int *base, int size, int num)
{
    int l = 0, r = size - 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (base[mid] >= num) r = mid;
        else l = mid;
    }

    if (base[l] >= num) return l;
    return r;
}

int main()
{
    int n; cin >> n;

    pair<int, int> p[n];

    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    sort(p, p + n);

    int len = 1, dp[n];
    dp[0] = p[0].second;
    for (int i = 1; i < n; i++)
    {
        if (p[i].second > dp[len - 1]) dp[len++] = p[i].second;
        else dp[binarySearch(dp, len, p[i].second)] = p[i].second;
    }

    cout << len;

    return 0;
}