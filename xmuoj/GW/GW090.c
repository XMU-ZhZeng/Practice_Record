#include <stdio.h>

int n, m;
int castle[50][50], flag[50][50] = { 0 };
int queue[5000][2], h, t;

// 获取二进制的第i位
int getBit(int n, int i) { return (n >> i) & 1; }


int bfs(int x, int y)
{
    h = 0, t = -1;
    ++t;
    queue[t][0] = x, queue[t][1] = y;
    flag[x][y] = 1;

    int count = 0;

    int dx[] = { 0, -1, 0, 1 }, dy[] = { -1, 0, 1, 0 }; // 西、北、東、南
    while (h <= t)
    {
        int x = queue[h][0], y = queue[h][1];
        ++h, ++count;


        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!getBit(castle[x][y], i) && !flag[nx][ny])
            {
                ++t;
                queue[t][0] = nx, queue[t][1] = ny;
                flag[nx][ny] = 1;
            }
        }
    }

    return count;
}


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &castle[i][j]);

    int cnt = 0, max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!flag[i][j]) // 沒走過
            {
                cnt++;
                int tmp = bfs(i, j);
                if (tmp > max) max = tmp;
            }
        }

    printf("%d\n%d", cnt, max);

    return 0;
}