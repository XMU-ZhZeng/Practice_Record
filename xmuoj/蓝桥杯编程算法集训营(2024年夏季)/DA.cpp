#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <utility>

int graph[1010][1000][2], idx[1010] = { 0 }; // 图
int rg[1010][1000][2], ri[1010] = { 0 };
int dist[1010]; // 反接最短距离

void dijkstra(int t, int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    dist[t] = 0;
    q.push(t);

    while (q.size())
    {
        int tmp = q.front();
        q.pop();

        for (int i = 0; i < ri[tmp]; i++)
        {
            if (dist[rg[tmp][i][0]] > dist[tmp] + rg[tmp][i][1])
            {
                dist[rg[tmp][i][0]] = dist[tmp] + rg[tmp][i][1];
                q.push(rg[tmp][i][0]);
            }        
        }
    }
}

struct Path
{
    int node; // 点编号
    int EF; // 估价函数
    int distance; // 已经过距离
    Path(int n, int d) : node(n), EF(d + dist[n]), distance(d) {}
};

struct ComparePath{ bool operator()(const Path& a, const Path& b) { return a.EF > b.EF; } };

int aStar(int n, int s, int t, int k)
{
    int cnt[1001] = { 0 };

    dijkstra(t, n);

    priority_queue<Path, vector<Path>, ComparePath> pq; 

    pq.push(Path(s, 0));

    while (pq.size())
    {
        auto tmp = pq.top();
        pq.pop();

        cnt[tmp.node]++;
        if (cnt[t] == k) return tmp.distance;

        for (int i = 0; i < idx[tmp.node]; i++)
            if (cnt[graph[tmp.node][i][0]] < k)
                pq.push(Path(graph[tmp.node][i][0], tmp.distance + graph[tmp.node][i][1]));
    }

    return -1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    while (m--) // 初始化图
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        graph[x][idx[x]][0] = y, graph[x][idx[x]][1] = z;
        idx[x]++;
        rg[y][ri[y]][0] = x, rg[y][ri[y]][1] = z;
        ri[y]++;
    }

    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    if (s == t) k++;

    int res = aStar(n, s, t, k);

    printf("%d", res);

    return 0;
}