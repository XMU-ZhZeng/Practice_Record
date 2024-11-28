#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

#define PII pair<int, int>

int N, V;
int Root;
PII vw[105];
vector<int> graph[105];
int dp[105][105];
bool visited[105][105] = { 0 };

int arr[105];
int DP(int root, int volume);
void dfs(int depth, int step, int root, int totalVolume, int volume)
{
    if (depth <= step + 1)
    {
        arr[step] = volume;
        int sum = 0;
        for (int i = 0; i < depth; i++) sum += DP(graph[root][i], arr[i]);
        dp[root][totalVolume] = max(dp[root][totalVolume], sum + vw[root].second);
        return;
    }
  
    for (int i = 0; i <= volume; i++)
    {
        arr[step] = i;
        dfs(depth, step + 1, root, totalVolume, volume - i);
    }
}


int DP(int root, int volume)
{
    if (volume < vw[root].first) return 0;
    if (visited[root][volume]) return dp[root][volume];
    
    visited[root][volume] = true;
    
    dp[root][volume] = vw[root].second;
     
    memset(arr, 0, graph[root].size() * sizeof(int));
    dfs(graph[root].size(), 0, root, volume, volume - vw[root].first);
  
    return dp[root][volume];
}


int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        int v, w, p; cin >> v >> w >> p;
        vw[i].first = v, vw[i].second = w;
        if (p == -1) Root = i;
        else graph[p].push_back(i);
    }
   
    cout << DP(Root, V);
   
    return 0;
}