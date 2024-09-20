#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int time = 0, longest = 0;
    while (n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        if (x >= 90 && x <= 140 && y >= 60 && y <= 90) time++;
        else if (time > longest) longest = time, time = 0;
    }
    if (time > longest) longest = time;

    printf("%d", longest);

    return 0;
}