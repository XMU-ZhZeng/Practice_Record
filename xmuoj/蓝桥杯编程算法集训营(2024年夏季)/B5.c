#include <stdio.h>

char S[1000000], P[100000];
int n, m, next[100000];

int main()
{
    scanf("%d %s %d %s", &n, P, &m, S);
    
    // 计算 next 数组
    next[1] = 0;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j > 0 && P[i] != P[j]) j = next[j];
        if (P[i - 1] == P[j]) j++;
        next[i] = j;
    }

    // 匹配
    for (int i = 0, j = 0; i < m;)
    {
        if (P[j] == S[i]) i++, j++; else if (j == 0) i++; else j = next[j];
        if (j == n) printf("%d ", i - n), j = next[j];
    }

    return 0;
}