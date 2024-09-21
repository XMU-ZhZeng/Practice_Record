#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>

#define PSS pair<string, string>
string bfs(string& start, string& end)
{
    set<string> st;
    st.insert(start);

    queue<PSS> q;
    q.push({start, ""});

    char d[] = {'u', 'l', 'd', 'r'};
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    while (q.size())
    {
        PSS t = q.front();
        q.pop();
        int idx = t.first.find('x');
        int x = idx / 3, y = idx % 3;

        if (t.first == end) return t.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

            swap(t.first[idx], t.first[nx * 3 + ny]);

            if (st.count(t.first))
            {
                swap(t.first[idx], t.first[nx * 3 + ny]);
                continue;
            }
            st.insert(t.first);
            q.push({t.first, t.second + d[i]});
            swap(t.first[idx], t.first[nx * 3 + ny]);
        }
    }
    
    return "unsolvable";
}

int main()
{
    string str, end = "12345678x";
    char tmp;
    for (int i = 0; i < 9; i++) cin >> tmp, str += tmp;

    cout << bfs(str, end) << endl;

    return 0;
}