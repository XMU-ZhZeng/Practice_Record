#include <stdio.h>

char matrix[41][21] = { 0 };

int n, cnt = 0;

int dx[] = {-1, 0, 0}, dy[] = {0, -1, 1}; // 下、左、右
void dfs(int x, int y, int step)
{
    if (step == n) { cnt++; return; }

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (matrix[nx][ny]) continue;

        matrix[nx][ny] = 1;
        dfs(nx, ny, step + 1);
        matrix[nx][ny] = 0;
    }
}


int main()
{
    scanf("%d", &n);
    
    matrix[21][0] = 1;
    dfs(21, 0, 0);
 
    printf("%d", cnt);

    return 0;
}