#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct edge { int a, b, w; };

int find(int x, int unionFind[])
{
    if (unionFind[x] != x) unionFind[x] = find(unionFind[x], unionFind);
    return unionFind[x];
}

int main()
{
    int n, m; cin >> n >> m;

    vector<edge> graph;

    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        graph.push_back({x, y, z});
    }

    sort(graph.begin(), graph.end(), [](const edge& a, const edge& b) { return a.w < b.w; });

    int unionFind[n + 1];
    for (int i = 1; i <= n; i++) unionFind[i] = i;

    int dist = 0;
    int cnt = 0;
    for (auto i : graph)
    {
        int x = find(i.a, unionFind), y = find(i.b, unionFind);
        if (x != y)
        {
            unionFind[x] = y;
            dist += i.w;
            cnt++;
        }
        if (cnt == n - 1) break;
    }

    if (cnt == n - 1) cout << dist << endl;
    else cout << "impossible" << endl;

    return 0;
}