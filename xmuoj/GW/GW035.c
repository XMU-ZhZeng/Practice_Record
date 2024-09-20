#include <stdio.h>

int Pell[1000001];

int main()
{
    int n;
    scanf("%d", &n);

    Pell[1] = 1, Pell[2] = 2;
    for (int i = 3; i <= 1000000; i++) Pell[i] = (2 * Pell[i - 1] + Pell[i - 2]) % 32767;

    while (n--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", Pell[x]);
    }

    return 0;
}