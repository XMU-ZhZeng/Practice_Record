#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    string command;
    int elem;
    set<int> s;
    multiset<int> ms;

    while (n--)
    {
        cin >> command >> elem;
        if ("add" == command) s.insert(elem), ms.insert(elem), cout << ms.count(elem) << endl;
        else if ("ask" == command) cout << s.count(elem) << ' ' << ms.count(elem) << endl;
        else if ("del" == command)
        {
            cout << ms.count(elem) << endl;
            for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
                if (*it == elem) ms.erase(it);
        }
    }

    return 0;
}