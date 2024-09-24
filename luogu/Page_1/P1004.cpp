#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int N; cin >> N;
    int matrix[11][11] = { 0 }, dp[11][11][22] = { 0 };

    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) matrix[x][y] = z;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = max(i, j) + 1; k <= min(i, j) + N; k++)
                {
                    dp[i][j][k] = max(max(dp[i-1][j][k-1], dp[i-1][j-1][k-1]), max(dp[i][j-1][k-1], dp[i][j][k-1])) + matrix[k-i][i] + matrix[k-j][j];
                    if (i == j) dp[i][j][k] -= matrix[k-i][i];
                }

    cout << dp[N][N][2 * N] << endl;

    return 0;
}