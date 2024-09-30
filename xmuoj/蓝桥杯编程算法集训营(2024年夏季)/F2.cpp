#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <algorithm>

int n, m;

#define PII pair<int, int>
#define PIII pair<PII, int>
vector<PIII> graph;

int mySet[100010][3] = { 0 };

int find(int x)
{
    while (mySet[x][0] != x) x = mySet[x][0];
    return x;
}

bool myCompare(const PIII& e1, const PIII& e2) { return e1.second < e2.second; }

int Kruskal()
{
    for (int i = 1; i <= n; i++) mySet[i][0] = i, mySet[i][2] = 1;
    
    sort(graph.begin(), graph.end(), myCompare);

    for (auto it : graph)
    {
        int x = it.first.first, y = it.first.second;
        int fx = find(x), fy = find(y);
        if (fx == fy) continue;
        else mySet[fx][0] = fy, mySet[fy][1] += it.second + mySet[fx][1], mySet[fy][2] += mySet[fx][2];

        if (mySet[fy][2] >= n) break;
    }


    int head = find(1);
    if (mySet[head][2] == n) return mySet[head][1];
    else return -1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph.push_back({{x, y}, z});
    }

    int res = Kruskal();

    if (-1 == res) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}