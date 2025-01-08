#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
int n, m;
int matrix[105][105];

void Floyd()
{
    for (int i = 1; i <= n; i++)           // 中间顶点
        for (int j = 1; j <= n; j++)       // 起始顶点   
            for (int k = 1; k <= n; k++)   // 终止顶点
                if (matrix[j][i] != INF && matrix[i][k] != INF)
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            matrix[i][j] = INF;
        matrix[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        matrix[u][v] = min(matrix[u][v], w);
        matrix[v][u] = matrix[u][v];
    }

    Floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (matrix[i][j] == INF ? 0 : matrix[i][j]) << " ";
        cout << endl;
    }

    return 0;
}