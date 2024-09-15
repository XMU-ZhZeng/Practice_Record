#include <stdio.h>

char hashSet[100000] = { 0 };
int num[100000][20];

int main()
{
    int n; scanf("%d", &n);
    while (n--)
    {
        char c; scanf(" %c", &c);
        int a; scanf("%d", &a);
        int hash = ((int)(a * 0.6180339887) % 49999) + 50000;
        int i;
        for (i = 0; i < hashSet[hash]; i++) if (num[hash][i] == a) break;
        if ('I' == c) { if (i == hashSet[hash]) num[hash][hashSet[hash]++] = a; }
        else { if (i == hashSet[hash]) printf("No\n"); else printf("Yes\n"); }
    }
    return 0;
}