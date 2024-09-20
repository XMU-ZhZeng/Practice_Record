#include <stdio.h>

int main()
{
    for (int i = 81; i <= 342; i++)
    {
        if ((i % 9 == i / 7 / 7 % 7) && (i % 7 == i / 9 / 9 % 9) && (i / 9 % 9 == i / 7 % 7))
        {
            printf("%d\n", i);
            printf("%d%d%d\n", i / 7 / 7 % 7, i / 7 % 7, i % 7);
            printf("%d%d%d\n", i / 9 / 9 % 9, i / 9 % 9, i % 9);
            break;
        }
    }

    return 0;
}