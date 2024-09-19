#include <stdio.h>

int graph[510][5100][2], cnt[510] = { 0 };
int dist[510];
int n, m;
int queue[100000], h, t;

void dijkstra()
{
    h = 0, t = -1;
    queue[++t] = 1;

    while (t >= h)
    {
        int tmp = queue[h++];

        for (int i = 0; i < cnt[tmp]; i++)
        {
            if (dist[graph[tmp][i][0]] > dist[tmp] + graph[tmp][i][1] && dist[tmp] != 1e9)
            {
                dist[graph[tmp][i][0]] = dist[tmp] + graph[tmp][i][1];
                queue[++t] = graph[tmp][i][0];
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    dist[1] = 0;
    for (int i = 2; i <=n; i++) dist[i] = 1e9;
    for (int i = 0; i < m; i++)
    {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        graph[x][cnt[x]][0] = y, graph[x][cnt[x]][1] = z;
        cnt[x]++;
    }

    dijkstra();

    printf("%d", (dist[n] == 1e9 ? -1 : dist[n]));

    return 0;
}