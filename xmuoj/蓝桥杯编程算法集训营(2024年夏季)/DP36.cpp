#include <iostream>
#include <stack>

using namespace std;

int dp[20][20][2] = { 0 };
int matrix[20][20] = { 0 };
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];
  
    // dp[n][m] = max(dp[n - 1][m] + matrix[n][0], dp[n - 1][m - 1] + matrix[n][1], ... , dp[n - 1][0] + matrix[n][m])
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= j; k++)
                if (dp[i][j][0] <= dp[i - 1][j - k][0] + matrix[i][k])
                {
                    dp[i][j][0] = dp[i - 1][j - k][0] + matrix[i][k];
                    dp[i][j][1] = k;
                }
  
    cout << dp[n][m][0] << endl;
    
    stack<int> s;
    int i = n, j = m;
    while (i)
    {
        s.push(dp[i][j][1]);
        j -= dp[i][j][1];
        i--;
    }
  
    i = 1;
    while (s.size())
    {
        cout << i << " " << s.top() << endl;
        s.pop();
        i++;
    }
    
    return 0;
}