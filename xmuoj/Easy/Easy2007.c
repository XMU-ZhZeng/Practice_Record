#include <stdio.h>

int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y)!= EOF)
    {
        if (x > y) { int temp = x; x = y; y = temp; }
        int squareSum = 0, cubeSum = 0;

        if (x % 2) { cubeSum = x * x * x, x++; }
        for (int i = x; i <= y; i += 2) squareSum += i * i;
        for (int i = x + 1; i <= y; i += 2) cubeSum += i * i * i;

        printf("%d %d\n", squareSum, cubeSum);
    }

    return 0;
}