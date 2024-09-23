#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int N; cin >> N;
    int matrix[11][11] = { 0 }, dp[11][11][11][11] = { 0 };

    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) matrix[x][y] = z;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                for (int q = 1; q <= N; q++)
                {
                    dp[i][j][k][q] = max(max(dp[i-1][j][k-1][q], dp[i-1][j][k][q-1]), max(dp[i][j-1][k-1][q], dp[i][j-1][k][q-1])) + matrix[i][j] + matrix[k][q];
                    if (i == k && j == q) dp[i][j][k][q] -= matrix[i][j];
                }

    cout << dp[N][N][N][N] << endl;

    return 0;
}