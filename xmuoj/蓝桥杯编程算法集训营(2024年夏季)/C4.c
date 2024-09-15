#include <stdio.h>

int point[100000], cnt[100000];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) point[i] = i, cnt[i] = 1;
    char c[3]; int a, b;
    while (m--)
    {
        scanf("%s", c);
        if ('C' == *c)
        {
            scanf("%d%d", &a, &b);
            while (point[a] != a) a = point[a];
            while (point[b] != b) b = point[b];
            if (a == b) continue;
            point[b] = a, cnt[a] += cnt[b];
        }
        else if ('1' == c[1])
        {
            scanf("%d%d", &a, &b);
            while (point[a] != a && a != b) a = point[a];
            while (point[b] != b && b != a) b = point[b];
            if (a == b) printf("Yes\n"); else printf("No\n");
        }
        else
        {
            scanf("%d", &a);
            while (point[a] != a) a = point[a];
            printf("%d\n", cnt[a]);
        }
    }
    return 0;
}