#include <stdio.h>
#include <ctype.h>

int main()
{
    char arr[256];
    gets(arr);

    char *p = arr;
    int cnt = 0;
    while (*p)
    {
        if (isdigit(*p)) cnt++;
        p++;
    }

    printf("%d", cnt);

    return 0;
}