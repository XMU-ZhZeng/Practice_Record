#include <stdio.h>

int graph[10001][100][2], cnt[10001] = { 0 };
int queue[1000000], h = 0, t = -1;
int dist[10001];

int BFS(int n)
{
    queue[++t] = 1; // 源点入队

    while (t >= h)
    {
        int tmp = queue[h];
        ++h;

        for (int i = 0; i < cnt[tmp]; i++)
        {
            if (dist[graph[tmp][i][0]] > dist[tmp] + graph[tmp][i][1])
            {
                dist[graph[tmp][i][0]] = dist[tmp] + graph[tmp][i][1]; // 更新
                queue[++t] = graph[tmp][i][0];// 入队
            }
        }
    }

    return (1e9 == dist[n] ? -1 : dist[n]);
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) // 初始化
    {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        if (x == y) { if (z < 0) { printf("impossible"); return 0; } else continue; }
        int j;
        for (j = 0; j < cnt[x]; j++) if (graph[x][j][0] == y) break;
        if (j == cnt[x]) cnt[x]++, graph[x][j][0] = y, graph[x][j][1] = z;
        else if (graph[x][j][1] > z) graph[x][j][1] = z;
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++) dist[i] = 1e9;

    int res = BFS(n);

    if (res == -1) printf("impossible");
    else printf("%d", res);

    return 0;
}