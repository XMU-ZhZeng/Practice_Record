#include <stdio.h>

int main()
{
    int h, r;
    scanf("%d%d", &h, &r);
    printf("%d", (int)(20000 / (3.14159 * r * r * h)) + 1);
    return 0;
}