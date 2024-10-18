#include <stdio.h>

int main()
{
    int a; scanf("%d", &a);
    if (1 == a % 2) printf("0 0");
    else printf("%d %d", a / 4 + !!(a % 4), a / 2);
    return 0;
}