#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <set>

using namespace std;

#define PII pair<int, int>

struct Compare
{
    bool operator()(const PII& a, const PII& b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<PII>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    set<int> s;
    s.insert(1);
    int dist = 0;
    priority_queue<PII, vector<PII>, Compare> pq;
    for (auto i : graph[1]) pq.push(i);
    
    while (s.size() != n && pq.size())
    {
        auto tmp = pq.top();
        pq.pop();
        if (s.count(tmp.first)) continue;
        s.insert(tmp.first);
        dist += tmp.second;
        for (auto i : graph[tmp.first]) pq.push(i);
    }

    if (s.size() == n) cout << dist << endl;
    else cout << "impossible" << endl;

    return 0;
}