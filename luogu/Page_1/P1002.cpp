#include <iostream>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    // 初始化棋盘
    long long board[n + 1][m + 1];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) board[i][j] = -1;
    board[x][y] = 0;
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2 , -1};
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
        board[nx][ny] = 0;
    }

    // 动态规划
    board[0][0] = 1;
    for (int i = 1; i <= n; i++) if (-1 == board[i][0]) board[i][0] = board[i - 1][0];
    for (int i = 1; i <= m; i++) if (-1 == board[0][i]) board[0][i] = board[0][i - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (-1 == board[i][j])
                board[i][j] = board[i - 1][j] + board[i][j - 1];

    cout << board[n][m] << endl;

    return 0;
}