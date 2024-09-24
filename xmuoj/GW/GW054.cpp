#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define PSI pair<string, int>

bool compare(const PSI& e1, const PSI& e2) { return (e1.second == e2.second ? e1.first < e2.first : e1.second > e2.second); }

int main()
{
    int n; cin >> n;
    vector<PSI> v;
    string name;
    int grade; 
    while (n--) cin >> name >> grade, v.push_back({name, grade});
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        if (i) cout << endl;
        cout << v[i].first << " " << v[i].second;
        if (i == 1) cout << " ";
    }
    return 0;
}