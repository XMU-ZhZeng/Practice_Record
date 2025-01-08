#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int matrix[55][55];
int dp[55][55][55][55] = { 0 };

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    
    for (int i = 1; i <= m; i++) // 第一条路径的行
        for (int j = 1; j <= n; j++) // 第一条路径的列
            for (int k = 1; k < i; k++) // 第二条路径的行
                // i+j-k 第二条路径的列
                dp[i][j][k][i+j-k] = max(max(dp[i-1][j][k-1][i+j-k], dp[i-1][j][k][i+j-k-1]), max(dp[i][j-1][k-1][i+j-k], dp[i][j-1][k][i+j-k-1])) + matrix[i][j] + matrix[k][i+j-k];
    
    cout << dp[m][n-1][m-1][n] << endl;
    
    return 0;
}