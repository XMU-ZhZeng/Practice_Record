#include <stdio.h>

int dist[205][205];
int n, m, k;

void floyd()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int q = 1; q <= n; q++)
                if (dist[j][i] != 1e9 && dist[i][q] != 1e9)  
                    if (dist[j][q] > dist[j][i] + dist[i][q])
                        dist[j][q] = dist[j][i] + dist[i][q];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) dist[i][j] = 1e9;
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        if (x == y) continue;
        if (z < dist[x][y]) dist[x][y] = z;
    }

    floyd();

    while (k--)
    {
        int a, b; scanf("%d%d", &a, &b);
        if (dist[a][b] != 1e9) printf("%d\n", dist[a][b]); else printf("impossible\n");
    }

    return 0;
}