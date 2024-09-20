#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[80];
    gets(str);

    char *p = str;
    while (*p)
    {
        if (isalpha(*p))
        {
            if ('z' == *p) printf("a");
            else if ('Z' == *p) printf("A");
            else printf("%c", *p + 1);
        }
        else printf("%c", *p);
        p++;
    }

    return 0;
}