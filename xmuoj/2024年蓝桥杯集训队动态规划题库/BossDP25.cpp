#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> v;
        while (n--)
        {
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }

        int cnt = 0;
        while (v.size())
        {
            cnt++;
            int cntUp = 1, cntDown = 1;
            int up = v[0], down = v[0];
            for (auto it : v)
            {
                if (it > up) up = it, cntUp++;
                else if (it < down) down = it, cntDown++;
            }

            int tmp = v[0];
            v.erase(v.begin());
            for (vector<int>::iterator it = v.begin(); it != v.end();)
            {
                if ((*it > tmp && cntUp > cntDown) || (*it < tmp && cntUp < cntDown))
                {
                    tmp = *it;
                    v.erase(it);
                }
                else it++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}