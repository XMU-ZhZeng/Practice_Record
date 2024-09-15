#include <stdio.h>

int ch[3100010][2] = { 0 }, idx = 1, node, num, max = 0;

int main()
{
    int n; scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        node = 0;
        for (int i = 30; i >= 0; i--) // 插入
        {
            int digit = (num >> i) & 1;
            if (!ch[node][digit]) ch[node][digit] = idx++;
            node = ch[node][digit];
        }
        node = 0;
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            int digit = (num >> i) & 1;
            if (ch[node][!digit]) node = ch[node][!digit], ans += (1 << i);
            else if (ch[node][digit]) node = ch[node][digit];
        }
        max = (max > ans ? max : ans);
    }
    printf("%d", max);
    return 0;
}