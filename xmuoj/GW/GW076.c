#include <stdio.h>

#define A 0
#define B 1
#define C 2

void Hanoi(int n, int src, int dest, int mid)
{
    if (n == 1)
    {
        printf("%c->%c\n", 'A' + src, 'A' + dest);
        return;
    }

    Hanoi(n - 1, src, mid, dest);
    Hanoi(1, src, dest, mid);
    Hanoi(n - 1, mid, dest, src);
}

int main()
{
    int n; scanf("%d", &n);

    Hanoi(n, A, C, B);

    return 0;
}