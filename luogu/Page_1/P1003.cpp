#include <iostream>
using namespace std;
#include <vector>

struct Carpet
{
    int a;
    int b;
    int g;
    int k;
    Carpet(int a, int b, int g, int k) : a(a), b(b), g(g), k(k) {}
};

int main()
{
    int n; cin >> n;

    vector<Carpet> v;
    while (n--)
    {
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        v.push_back({a, b, g, k});
    }

    int x, y; cin >> x >> y;

    int i;
    for (i = v.size() - 1; i >= 0; i--)
        if (x >= v[i].a && x <= v[i].a + v[i].g && y >= v[i].b && y <= v[i].b + v[i].k) break;

    if (i != -1) i++;
    cout << i << endl;

    return 0;
}