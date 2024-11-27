#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    if (n % 10) cout << 0;
    else
    {
        int cnt = 0;
        for (int i = -100; (i += 100) <= n;)
            for (int j = i - 50; (j += 50) <= n;)
                for (int k = j - 20; (k += 20) <= n;)
                    for (int z = k - 10; (z += 10) <= n;)
                        if (z == n) cnt++;
        cout << cnt;
    }
    return 0;
}