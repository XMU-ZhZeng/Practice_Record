#include <iostream>
#include <cmath>

int members[100001][2];

int main()
{
    int n = 0; scanf("%d", &n);
    members[0][0] = 1, members[0][1] = 1000000000;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &members[i][0], &members[i][1]);
        int idx = 0, minDiff = members[0][1] - members[i][1];
        for (int j = 1; j < i; j++)
        {
            int diff = members[i][1] - members[j][1];
            if (abs(diff) < minDiff) idx = j, minDiff = abs(diff);
            else if (abs(diff) == minDiff) if (diff > 0) idx = j;
        }
        printf("%d %d\n", members[i][0], members[idx][0]);
    }

    return 0;
}