#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int a, b;
    
    while (cin >> a >> b && a && b)
    {
        vector<int> A;
        while (a--) { int tmp; cin >> tmp; A.push_back(tmp); }
        while (b--)
        {
            int tmp; cin >> tmp;
            auto it = find(A.begin(), A.end(), tmp);
            if (it!= A.end()) A.erase(it);
        }

        sort(A.begin(), A.end());

        if (A.size())
        {
            for (auto i : A) cout << i << " ";
            cout << endl;
        }
        else cout << "NULL" << endl;
     }

    return 0;
}