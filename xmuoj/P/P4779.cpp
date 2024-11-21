#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <utility>

#define PII pair<int, int>

vector<PII> graph[150001];
int dist[150001];
int n, m;

void dijkstra()
{
    
    priority_queue<int> q;
    q.push(1);

    while (q.size())
    {   
        int t = q.top();
        vector<PII>& vt = graph[t];
        q.pop();

        for (auto i : vt)
        {
            if (dist[i.first] > dist[t] + i.second)
            {
                dist[i.first] = dist[t] + i.second;
                q.push(i.first);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 2; i <= n; i++) dist[i] = 0x3f3f3f3f;
    dist[1] = 0;

    dijkstra();

    for (int i = 1; i <= n; i++) cout << (dist[i] != 0x3f3f3f3f ? dist[i] : -1) << " ";

    return 0;
}