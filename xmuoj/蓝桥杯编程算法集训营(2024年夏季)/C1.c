#include <stdio.h>

int ch[100000][26] = { 0 };
int idx = 1, node = 0, cnt[100000] = { 0 };
char c, str[100000], *p;

int main()
{
    int n; scanf("%d", &n);
    while (n--)
    {
        scanf(" %c%s", &c, str);
        if ('I' == c) // 插入
        {
            for (p = str, node = 0; *p; p++)
            {
                int j = *p - 'a';
                if (ch[node][j] == 0) ch[node][j] = idx++;
                node = ch[node][j];
            }
            cnt[node]++;
        }
        else // 查找
        {
            for (p = str, node = 0; *p; p++)
            {
                int j = *p - 'a';
                if (ch[node][j] == 0) { node = 0; break; }
                node = ch[node][j];
            }
            printf("%d\n", cnt[node]);
        }
    }
    return 0;
}