#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <algorithm>

#define PII pair<int, int>

bool compare(const PII& e1, const PII& e2) { return (e1.second == e2.second ? e1.first < e2.first : e1.second > e2.second); }

int main()
{
    int n, m; cin >> n >> m;
    vector<PII> v;
    int id, grade;
    while (n--) cin >> id >> grade, v.push_back({id, grade});
    sort(v.begin(), v.end(), compare);
    int num = (int)(m * 1.5);
    while (v[num].second == v[num - 1].second) num++;
    cout << v[num - 1].second << " " << num << endl;
    for (int i = 0; i < num; i++)
    {
        if (i) cout << endl;
        cout << v[i].first << " " << v[i].second;
    }
    return 0;
}