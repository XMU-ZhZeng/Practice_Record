#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct edge
{
    int x, y, z;
};

struct Compare
{
    bool operator()(edge& e1, edge& e2)
    {
        return e1.z > e2.z;
    }
};

int n, m;
int unionSet[310];
priority_queue<edge, vector<edge>, Compare> pq;

int find(int x)
{
    if (x != unionSet[x]) return find(unionSet[x]);
    return x;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) unionSet[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        pq.push({x, y, z});
    }
  
    int cnt = 0;
    edge tmp;
    while (cnt != n - 1)
    {
        tmp = pq.top();
        pq.pop();
      
        int x = find(tmp.x), y = find(tmp.y);
        if (x == y) continue;
        else
        {
            cnt++;
            unionSet[y] = x;
        }
    }
  
    cout << n - 1 << " " << tmp.z;
  
    return 0;
}