#include <iostream>
#include <algorithm>

using namespace std;

int arr[105][2];
int dp[105][1010] = { 0 };
bool visited[105][1010] = { 0 };

int DP(int M, int T)
{
    if (M == 1) return (T >= arr[1][0] ? arr[1][1] : 0);
    if (visited[M][T]) return dp[M][T];
  
  	visited[M][T] = true;
    if (T < arr[M][0]) return dp[M][T] = DP(M - 1, T);
    return dp[M][T] = max(DP(M - 1, T - arr[M][0]) + arr[M][1], DP(M - 1, T));
}

int main()
{
    int T, M; cin >> T >> M;
    for (int i = 1; i <= M; i++) cin >> arr[i][0] >> arr[i][1];
  
    cout << DP(M, T);
  
    return 0;
}
