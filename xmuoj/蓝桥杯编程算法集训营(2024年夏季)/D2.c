#include <stdio.h>

int graph[10010][3];
int dist[510];

int main()
{
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i][0], &graph[i][1], &graph[i][2]);

    dist[1] = 0;
    for (int i = 2; i <= n; i++) dist[i] = 1e9;

    for (int i = 0; i < k; i++)
    {
        int dtmp[510];
        for (int j = 1; j <= n; j++) dtmp[j] = dist[j];
        for (int j = 1; j <= m; j++)
        {
            int u = graph[j][0], v = graph[j][1], w = graph[j][2];
            if (dist[u] + w < dtmp[v] && dist[u]!= 1e9) dtmp[v] = dist[u] + w;
        }
        for (int j = 1; j <= n; j++) dist[j] = dtmp[j];
    }

    if (dist[n] == 1e9) printf("impossible"); else printf("%d", dist[n]);

    return 0;
}