#include <iostream>
using namespace std;
#include <vector>

int n, m;
char circle[301];

int main()
{
    int f = 0;
    while (scanf("%d%d", &n, &m) != EOF && n && m)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(i);

        int idx = -1;
        while (v.size() > 1)
        {
            idx += m;
            idx %= v.size();
            auto it = v.begin() + idx;
            v.erase(it);
            idx--;
        }

        printf("%d\n", v[0]);
    }

    return 0;
}