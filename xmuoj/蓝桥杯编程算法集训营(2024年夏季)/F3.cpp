#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <queue>

int n, m;
unsigned char color[100010] = { 0 };
vector<vector<int>> graph(100010);

bool Color()
{
    for (int j = 1; j <= n; j++)
    {   

        if (!color[j])
        {
            queue<int> q;
            q.push(j);
            color[j] = 1;
            while (q.size())
            {
                int tmp = q.front();
                q.pop();

                for (int i = 0; i < graph[tmp].size(); i++)
                {
                    if (0 == color[graph[tmp][i]]) color[graph[tmp][i]] = -color[tmp], q.push(graph[tmp][i]);
                    else if (color[graph[tmp][i]] == color[tmp]) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (Color()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}