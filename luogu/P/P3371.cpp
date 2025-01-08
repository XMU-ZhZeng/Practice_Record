#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, s;
struct node
{
    int id;
    int dist;
};
bool operator<(const node &a, const node &b) { return a.dist > b.dist; }

void Dijkstra(vector<vector<pair<int, int>>> graph)
{
    vector<int> dist(n + 1, 0x7fffffff);
    bool visited[n + 1] = {0};
    dist[s] = 0;
    visited[s] = 1;
    priority_queue<node> pq;
    pq.push(node{s, 0});
    
    for (int i = 0; i < n - 1 && pq.size(); i++)
    {
        int u = pq.top().id;
        pq.pop();

        for (int j = 0; j < graph[u].size(); j++)
        {
            int v = graph[u][j].first;
            int w = graph[u][j].second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(node{v, dist[v]});
            }
        }
        while (pq.size() && visited[pq.top().id]) pq.pop();
        if (pq.size()) visited[pq.top().id] = 1;
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}

int main()
{   
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    Dijkstra(graph);

    return 0;
}