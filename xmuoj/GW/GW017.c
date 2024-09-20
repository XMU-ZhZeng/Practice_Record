#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x;
    long long sun = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        sun += x;
    }

    printf("%lld %.5lf", sun, (double)sun / n);

    return 0;
}