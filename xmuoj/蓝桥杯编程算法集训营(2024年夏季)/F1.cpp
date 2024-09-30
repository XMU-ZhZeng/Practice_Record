#include <iostream>
using namespace std;
#include <set>
#include <queue>
#include <vector>
#include <utility>

#define PII pair<int, int>
#define PIII pair<int, PII>

int n, m;

struct Compare { bool operator()(const PIII& e1, const PIII& e2) { return e1.second.second > e2.second.second; } };

int Prim(vector<vector<PII>> v)
{
    int sum = 0;

    priority_queue<PIII, vector<PIII>, Compare> pq;
    set<int> s;

    s.insert(1);
    for (auto it : v[1]) pq.push({1, {it.first, it.second}});

    while ((s.size() < n) && pq.size())
    {
        PIII tmp = pq.top();
        pq.pop();

        if (s.find(tmp.second.first) != s.end()) continue;
        
        s.insert(tmp.second.first);
        sum += tmp.second.second;
        for (auto it : v[tmp.second.first]) pq.push({tmp.second.first, {it.first, it.second}});
    }

    if (s.size() == n) return sum;
    else return -1;
}

int main()
{
    cin >> n >> m;
    vector<vector<PII>> v(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    int res = Prim(v);

    if (-1 == res) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}