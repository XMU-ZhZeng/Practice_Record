#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int N, M;

struct Edge { int u, v, w; Edge() {}; Edge(int u, int v, int w) : u(u), v(v), w(w) {};};
struct Compare
{
    bool operator()(const Edge &a, const Edge &b) { return a.w > b.w; }
};
// Prim
void Prim()
{
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    set<int> visited;
    priority_queue<Edge, vector<Edge>, Compare> pq;
    visited.insert(1);
    for (auto &p : graph[1]) pq.push(Edge(1, p.first, p.second));
    int ans = 0;
    while (visited.size() < N && !pq.empty())
    {
        Edge e = pq.top(); pq.pop();
        if (visited.find(e.v) != visited.end()) continue;
        visited.insert(e.v);
        ans += e.w;
        for (auto &p : graph[e.v]) pq.push(Edge(e.v, p.first, p.second));
    }
    if (visited.size() < N) cout << "orz";
    else cout << ans;
}

// Kruskal
void Kruskal()
{
    vector<Edge> edges;
    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) { return a.w < b.w; });
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;
    int ans = 0;
    int cnt = 0;
    for (auto &e : edges)
    {
        int u = e.u, v = e.v, w = e.w;
        while (parent[u] != u) u = parent[u];
        while (parent[v] != v) v = parent[v];
        if (u == v) continue;
        parent[v] = u;
        ans += w;
        cnt++;
    }
    if (cnt != N - 1) cout << "orz";
    else cout << ans;
}

int main()
{
    cin >> N >> M;
    Prim();
    // Kruskal();
    return 0;
}