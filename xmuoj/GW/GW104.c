#include <stdio.h>

int highBit(int n)
{
    int i = 0;
    while (n) n >>= 1, i++;
    return i;
}

void print2(int n)
{
    int flag = 0;
    while (n)
    {
        if (!flag) flag = 1;
        else printf("+");
        int h = highBit(n);
        n -= (1 << (h - 1));

        if (h > 2)
        {
            printf("2(");
            print2(h - 1);
            printf(")");
        }
        else if (h == 2) printf("2");
        else printf("2(0)");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print2(n);
    return 0;
}