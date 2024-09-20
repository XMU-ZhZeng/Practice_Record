#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);

    if (abs(x) > 1 || abs(y) > 1) printf("no");
    else printf("yes");

    return 0;
}