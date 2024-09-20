#include <stdio.h>

int main()
{
    int arr[1000] = { 0 };
    for (int i = 100; i <= 999; i++)
    {
        int a = i / 100, b = i / 10 % 10, c = i % 10;
        if (a * a * a + b * b * b + c * c * c == i) arr[i] = 1;
    }

    int m, n;
    while (scanf("%d%d", &m, &n)!= EOF)
    {
        int flag = 0;
        for (int i = m; i <= n; i++)
        {
            if (arr[i])
            {
                if (flag) printf(" ");
                printf("%d", i);
                flag = 1;
            }
        }
        if (!flag) printf("no");
        printf("\n");
    }

    return 0;
}