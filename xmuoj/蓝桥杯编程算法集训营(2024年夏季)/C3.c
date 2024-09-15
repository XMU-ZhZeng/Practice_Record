#include <stdio.h>

int num[100000];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) num[i] = i;
    while (m--)
    {
        char c; scanf(" %c", &c);
        int a, b; scanf("%d%d", &a, &b);
        if ('M' == c) // 合并
        {   
            while (num[a] != a) a = num[a];
            while (num[b] != b) b = num[b];
            num[a] = b;
        }
        else // 查询
        {
            while (num[a] != a && a != b) a = num[a];
            while (num[b] != b && b != a) b = num[b];
            if (a == b) printf("Yes\n"); else printf("No\n");
        }
    }
    return 0;
}