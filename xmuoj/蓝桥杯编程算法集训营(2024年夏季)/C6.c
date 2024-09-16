#include <stdio.h>
#include <string.h>

char str[100010];

int compare(char *str1, int len1, char *str2, int len2)
{
    if (len1 != len2) return 0;
    for (int i = 0; i < len1; i++) if (str1[i] != str2[i]) return 0;
    return 1;
}

int main()
{
    int n, m; scanf("%d%d%s", &n, &m, str);
    while (m--)
    {
        int l1, r1, l2, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (compare(str + l1 - 1, r1 - l1 + 1, str + l2 - 1, r2 - l2 + 1)) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}