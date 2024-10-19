#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main()
{   
    int m; scanf("%d", &m);

    while (m--)
    {
        int n, k; scanf("%d%d", &n, &k);
        vector<int> v;

        int x;
        while (n--)
        {
            scanf("%d", &x);
            v.push_back(x);
        }

        while (k--) next_permutation(v.begin(), v.end());

        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            if (it != v.begin()) printf(" ");
            printf("%d", *it);
        }
        
        if (m) printf("\n");
    }

    return 0;
}