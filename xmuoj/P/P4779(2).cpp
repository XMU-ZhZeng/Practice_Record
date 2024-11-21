#include <iostream>
using namespace std;

int graph[510][5100][2], cnt[510] = { 0 };
int state[510] = { 0 };
int dest[510];

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        graph[x][cnt[x]][0] = y, graph[x][cnt[x]][1] = z;
        cnt[x]++;
    }

    for (int i = 0; i <= n; i++) dest[i] = 0x7fffffff;
    dest[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
            if (!state[j] && (dest[j] < dest[tmp]))
                tmp = j;
        state[tmp] = 1;

        for (int j = 0; j < cnt[tmp]; j++)
        {
            if (state[graph[tmp][j][0]]) continue;
            
            if (dest[tmp] + graph[tmp][j][1] < dest[graph[tmp][j][0]])  
                dest[graph[tmp][j][0]] = dest[tmp] + graph[tmp][j][1];
        }
    }

    for (int i = 1; i <= n; i++) cout << (dest[i] != 0x7fffffff ? dest[i] : -1) << " ";

    return 0;
}