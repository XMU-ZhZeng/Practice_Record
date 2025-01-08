#include <iostream>
#include <cstring>

using namespace std;

char a[10] = { 1 };

bool check(int x)
{
    for (int i = 0; i < 3; i++)
        if (a[x % 10]) return false;
        else a[x % 10]++, x /= 10;
    
    return true;
}
int main()
{
    for (int i = 192; i <= 329; i++)
    {
        memset(a + 1, 0, 9);
        if (check(i) && check(2 * i) && check(3 * i))
        {
            if (i != 192) cout << endl;
            cout << i << " " << 2 * i << " " << 3 * i;
        }
    }

    return 0;
}