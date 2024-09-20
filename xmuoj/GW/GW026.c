#include <stdio.h>

int main()
{
    int M, N, X;
    scanf("%d%d%d", &M, &N, &X);

    while (X * N >= M)
    {
        X = (X * N - M) / N;
        N += M / N;
    }

    printf("%d", N);

    return 0;
}

