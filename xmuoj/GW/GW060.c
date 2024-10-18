#include <stdio.h>

int N, M;
int budgets[100000];

int check(int budget)
{
    int count = 1, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += budgets[i];
        if (sum > budget)
        {
            count++;
            sum = budgets[i];
        }
        if (count > M) break;
    }
    if (count > M) return 0; // budget 偏小
    return 1; // budget 偏大
}

int findMin(int max, int min)
{
    while (max - min > 1)
    {
        int mid = (max + min) / 2;
        if (check(mid)) max = mid;
        else min = mid;
    }

    if (check(min)) return min;
    return max;
}

int main()
{
    scanf("%d%d", &N, &M);
    int sum = 0, max = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &budgets[i]);
        sum += budgets[i];
        if (budgets[i] > max) max = budgets[i];
    }
    printf("%d", findMin(sum, max));
    return 0;
}