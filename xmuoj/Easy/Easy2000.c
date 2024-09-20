#include <stdio.h>

void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }    

int main()
{
    char a, b, c;
    while (scanf(" %c%c%c", &a, &b, &c)!= EOF)
    {
        if (a > b) swap(&a, &b);
        if (a > c) swap(&a, &c);
        if (b > c) swap(&b, &c);
        printf("%c %c %c\n", a, b, c);
    }

    return 0;
}