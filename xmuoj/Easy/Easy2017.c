#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);

    char str[10000];
    while (n--)
    {
        fgets(str, 10000, stdin);
        int cnt = 0;
        for (int i = 0; str[i]!= '\0'; i++) cnt += !!isdigit(str[i]);
        printf("%d\n", cnt);
    }

    return 0;
}